/* ********************************************************************************************** */
/*                                                                                                */
/*   Mini Access Detector Project                                      :::::::::        :::       */
/*   header.h                                                         :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/10/31 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/11/02 09:48:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*                                                                                                */
/* ********************************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <Arduino.h>
#include <WiFi.h>
#include <stdio.h>
#include "credentials.h"
#include <WiFiClientSecure.h>
#include <WiFiMulti.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ElegantOTA.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <esp_system.h>
#include <esp_sleep.h>
#include <esp32/ulp.h>
#include <driver/adc.h>

#define SOFTWARE_VERSION        1.00
//#define PRIVATE                                                       // comment out this line to allow bot answer in any Telegram chat
#define DEBUG                                                         // comment out this line to turn off Serial output
#ifdef DEBUG
  #define DEBUG_PRINTF(x, y) Serial.printf(x, y)
  #define DEBUG_PRINTS(q, w, e, r, t) Serial.printf(q, w, e, r, t)
#else
  #define DEBUG_PRINTF(x, y)
  #define DEBUG_PRINTS(q, w, e, r, t)
#endif
#define DOOR_SENSOR_PIN         12
#define TOUCH_BUTTON_PIN        4
#define CONNECT_TIMEOUT         5000                                  // WiFi timeout per each AP, in milliseconds. Increase if cannot connect.
#define WAIT_FOR_OTA_LIMIT      60                                    // in seconds
#define WAIT_FOR_MESSAGES_LIMIT 80                                    // in seconds, 1 == 2 seconds (80 == 160 seconds == 2,5 minutes)
#define WAIT_THE_DOOR           180000

WiFiMulti wifiMulti;
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
AsyncWebServer server(80);

String  g_door_name = "The door";
bool    g_door_state;
bool    g_reboot;

#include "other.h"
#include "wifi_networking.h"
#include "ota_mode.h"
#include "telegram_bot_handling.h"
#include "power_down_recovery.h"

short     IRAM_ATTR ft_new_messages(short numNewMessages);
void      IRAM_ATTR ft_check_incomming_messages(short cycles);
void      IRAM_ATTR ft_wifi_list(void);
short     ft_ota_mode(String chat_id);
short     ft_battery_check(void);
void      IRAM_ATTR ft_delay(unsigned int time_in_millis);
void      ft_go_to_sleep(void);
void      ft_power_down_recovery(void);

#endif
 
