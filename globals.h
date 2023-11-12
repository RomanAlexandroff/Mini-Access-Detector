/* ********************************************************************************************** */
/*                                                                                                */
/*   Mini Access Detector Project                                      :::::::::        :::       */
/*   globals.h                                                         :+:    :+:     :+: :+:     */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/10/31 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/11/12 10:35:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   Global variables and objects declaration                                                     */
/*                                                                                                */
/* ********************************************************************************************** */

#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <WiFiClientSecure.h>
#include <WiFiMulti.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <UniversalTelegramBot.h>
#include "credentials.h"

extern WiFiMulti wifiMulti;
extern WiFiClientSecure client;
extern UniversalTelegramBot bot;
extern AsyncWebServer server;

extern String  g_door_name;
extern bool    g_door_state;
extern bool    g_reboot;

#endif
