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
/* ********************************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <Arduino.h>
#include <WiFi.h>
#include <ElegantOTA.h>
#include <stdio.h>
#include <ArduinoJson.h>
#include <esp_system.h>
#include <esp_sleep.h>
#include <esp32/ulp.h>
#include <driver/adc.h>
#include "globals.h"

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

short     IRAM_ATTR ft_new_messages(short numNewMessages);
void      IRAM_ATTR ft_check_incomming_messages(short cycles);
void      IRAM_ATTR ft_wifi_list(void);
short     ft_ota_mode(String chat_id);
void      ft_go_to_sleep(void);
void      IRAM_ATTR ft_delay(unsigned int time_in_millis);
void      IRAM_ATTR ft_door_isr(void);
void      IRAM_ATTR ft_button_isr(void);
short     ft_battery_check(void);
void      ft_power_down_recovery(void);

#endif
 
