/* ********************************************************************************************** */
/*                                                                                                */
/*   Mini Access Detector Project                                      :::::::::        :::       */
/*   globals.cpp                                                      :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/10/31 14:49:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/11/12 10:35:41                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   Global variables and objects initialization                                                  */
/*                                                                                                */
/* ********************************************************************************************** */

#include "globals.h"

WiFiMulti wifiMulti;
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
AsyncWebServer server(80);

String  g_door_name = "The door";
bool    g_door_state;
bool    g_reboot;
