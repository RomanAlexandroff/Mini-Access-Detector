/* ********************************************************************************************** */
/*                                                                                                */
/*   Mini Access Detector Project                                      :::::::::        :::       */
/*   other.cpp                                                        :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/10/31 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/11/02 09:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   This file contains all the little utility functions that are not too important to have       */
/*   their own personal files. They are not necesarrily connected with each other logically.      */
/*                                                                                                */
/* ********************************************************************************************** */

#include "header.h"

void  ft_check_incomming_messages(short cycles);

void  ft_go_to_sleep(void)
{
    if (g_reboot)
        esp_restart();
    DEBUG_PRINTF("The device was running for %d second(s) this time ", (millis() / 1000));
    DEBUG_PRINTF("and now is going to sleep until the next wake-up interrupt\n", "");
    DEBUG_PRINTF("\nDEVICE STOP\n\n\n", "");
    esp_deep_sleep_start();
}

void  IRAM_ATTR ft_delay(unsigned int time_in_millis)
{
    esp_sleep_enable_timer_wakeup(time_in_millis * 1000);
    esp_light_sleep_start();
}

void  IRAM_ATTR ft_door_isr(void)
{
    g_door_state = false; //closed
    DEBUG_PRINTF("%s has just been closed!\n", g_door_name.c_str());
}

void  IRAM_ATTR ft_button_isr(void)
{
    String  message;

    bot.sendMessage(CHAT_ID, "Accessing Settings", "");
    DEBUG_PRINTF("\nTouch interrupt detected. Accessing Settings\n", "");
    ft_delay(2000);
    message = "Here are the commands available to you:";   
    message += "\n\n status - to show connection info and battery status,";
    message += "\n ota - to activate firmware update mode (for developers).";
    message += "\n reboot - to restart the device,";
    message += "\n off - to exit settings and switch off the device,";
    message += "\n\nEvery command should start with \"/\" sign";
    bot.sendMessage(CHAT_ID, message, "");
    ft_check_incomming_messages(0);
}

short  ft_battery_check(void)
{
    short i;
    short battery;

    i = 4;
    while (i)
    {
        battery += ceil((adc1_get_raw(ADC1_CHANNEL_0) - 650) / 12.62);            // see ReadMe regarding these constants
        ft_delay(100);
        i--;
    }
    battery = battery / 4;                                                        // counting average of 4 samples
    if (battery <= 0)
        battery = 0;
    if (battery >= 100)
        battery = 100;
    return (battery);
}
 
