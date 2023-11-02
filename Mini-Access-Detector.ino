/* ********************************************************************************************** */
/*                                                                                                */
/*   Mini Access Detector Project                                      :::::::::        :::       */
/*   Mini_Access_Detector.ino                                         :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/10/31 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/11/02 09:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   This is the Main file of the Soft Tracker Project. This firmware allows User to track        */
/*   an approximate location of ESP32-S2 based devices via Telegram chat notifications.           */
/*   More details in the ReadMe file.                                                             */
/*                                                                                                */
/* ********************************************************************************************** */

#include "header.h"

/*

Принцип работы:

- от открывания двери срабатывает магнитный ключ на GPIO 12
- ESP просыпается из Deep Sleep от прерывания,
- ESP начинает отсчитывать millis открытия двери,
- подключается к Wi-Fi
- посылает сообщение о открытии двери в Телеграм чат
- замеряет заряд своего аккумулятора
    - если заряд низкий, посылает об этом сообщение
- начинает ждать прерывания закритием двери
- каждые 5 минут посылает сообщение, что дверь всё ещё открыта
    - если спустя 3 сообщения дверь всё ещё открыта,
      ESP переходит в deep sleep самостоятельно 
    
- параллельно с описанными выше действиями, ESP следит за прерыванием
  на GPIO 12, которое произойдёт от закрытия двери
- в момент прерывания ESP фиксирует значение millis
    - если значение millis уже больше 5 минут, то ESP отправляет сообщение
      что дверь была закрыта
- ESP переходит в deep sleep 

- параллельно с описанными выше действиями, ESP следит за прерыванием
  на touch GPIO 4, которое произойдёт от прикосновения к тач-поверхности
- в момент прерывания ESP блокирует выкоючение, автоматически переходит 
  в режим настройки через Telegram чат и активирует OTA update
  

ESP32-S2-WROOM module interrupt wake-up PINS:
GPIO 0, 2, 4, 5, 12, 13, 14, 15, 25, 26, 33, 34, 35, 36, 37, 38, 39
ESP32-S2-WROOM module touch PINS:
GPIO 0, 2, 4,                15,         33, 34, 35, 36, 37, 38, 39

ESP32-C3-01M module interrupt wake-up PINS:
GPIO 4, 5, 6, 8, 9, 10
ESP32-C3-01M module does not have any touch PINS.

 */


void  setup(void)
{
    int i;

    #ifdef DEBUG
        Serial.begin(115200);
        DEBUG_PRINTF("\n\nDEVICE START\nversion %f\n", float(SOFTWARE_VERSION));
    #endif
    g_door_state = true; //open
    pinMode(DOOR_SENSOR_PIN, INPUT_PULLUP);
    attachInterrupt(DOOR_SENSOR_PIN, ft_door_isr, FALLING);
    WiFi.mode(WIFI_STA);
    WiFi.persistent(true);
    client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
    ft_wifi_list();
    if (wifiMulti.run(CONNECT_TIMEOUT) == WL_CONNECTED) 
    {
        ft_power_down_recovery();
        touchAttachInterrupt(TOUCH_BUTTON_PIN, ft_button_isr, 30);
        bot.sendMessage(CHAT_ID, String(g_door_name + " has just been opened"), "");
        DEBUG_PRINTF("%s has just been opened\n", g_door_name.c_str());
        if (ft_battery_check() <= 15)
        {
            bot.sendMessage(CHAT_ID, "My battery is low. Charge me when you have time!", "");
            DEBUG_PRINTF("My battery is low. Charge me when you have time!", "");
        }
        i = 3;
        while (i && g_door_state)
        {
            ft_delay(WAIT_THE_DOOR);
            bot.sendMessage(CHAT_ID, String(g_door_name + " is still open"), "");
            DEBUG_PRINTF("%s is still open\n", g_door_name.c_str());
            i--;
        }
        if (i < 3 && !g_door_state)
        {
            bot.sendMessage(CHAT_ID, String(g_door_name + " is now closed"), "");
            DEBUG_PRINTF("%s is now closed\n", g_door_name.c_str());
        }
        if (i < 3 && g_door_state)
        {
            bot.sendMessage(CHAT_ID, String("I am going to sleep now, but " + g_door_name + " is still open!"), "");
            DEBUG_PRINTF("I am going to sleep now, but %s is still open!\n", g_door_name.c_str());
        }
    }
    ft_go_to_sleep();
}

void  loop(void) { /* NOTHING IS HERE */ }
 
