/* ********************************************************************************************** */
/*                                                                                                */
/*   IoT  Name  Badge  ESP32-C3                                        :::::::::        :::       */
/*   wifi_list.h                                                      :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/09/27 18:14:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/10/18 17:45:10                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   List of known Wi-Fi networks in accordance with the WiFiMulti library. More                  */
/*   networks credentials can be added in an identical fasion ("SSID", "password"). The           */
/*   list must be called before the wifiMulti.run() function, which initiates connection.         */
/*                                                                                                */
/* ********************************************************************************************** */

void  IRAM_ATTR ft_wifi_list(void)
{
    wifiMulti.addAP(SSID1, PASSWORD1);
    wifiMulti.addAP(BACKUP_SSID1, BACKUP_PASSWORD1);
    wifiMulti.addAP(BACKUP_SSID2, BACKUP_PASSWORD2);
}
 
