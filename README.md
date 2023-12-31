# The Mini Access Detector

## About the Project
  
 The Mini Access Detector is a compact and versatile device designed to detect door openings and send notifications to a Telegram chat. It is based on the ESP32-S2 microcontroller, providing powerful capabilities in a small form factor. Install the Mini Access Detector on the desired access point, such as a door. When the door is opened, the reed switch will detect the magnetic field change triggered by the neodymium magnet and notify the configured Telegram chat.
 
 
## Features

 - opening detection: The Mini Access Detector is specifically designed to detect openings of anything that can be opened. It can be easily installed on doors, windows, drawers, boxes, safes, and more.
 - Telegram Notification: Whenever a door is opened, the Mini Access Detector sends a notification to a designated Telegram chat. This allows you to stay informed about access events in real time.
 - OTA Capability: The device supports Over-The-Air (OTA) updates, enabling you to easily update the firmware remotely without the need for physical access to the device. This ensures that you can benefit from future enhancements and bug fixes effortlessly.
 - low power: The Mini Access Detector is optimized for low power consumption. It turns on upon an event which allows it to operate on a single charge for months. This ensures long-term reliability and eliminates the need for frequent battery chargings.
 
 
## Hardware

 A single device requires the following components:
 - ESP32-S2 Module: it is a compact Wi-Fi microcontroller board, which provides the processing power and connectivity required for the Mini Access Detector.
 - Li-Ion 230 mAh Battery with protection: this rechargeable lithium-ion battery with a capacity of 230 mAh powers the Mini Access Detector. It ensures that the device can operate on a single charge for an extended period.
 - Li-Ion Battery Charger with microUSB port: the Li-Ion battery charger is responsible for recharging the battery. It features a microUSB port, allowing convenient charging from any 5V power source such as a computer or a USB charger.
 - Power Path Controlling Circuit or IC: switches the microcontroller's power supply from the battery to the charger and back, allowing the battery to charge and the microcontroller to keep working.
 - Reed Switch, Normally Closed (NC): The reed switch is a mechanical magnetic sensor that detects presence or abcense of a magnetic field. The Mini Access Detector utilizes a Normally Closed (NC) reed switch, which means it is in a closed state by default and opens when a magnetic field is detected.
 - Neodymium Magnet: a tiny neodymium magnet is used in conjunction with the reed switch. Removing the magnet from the reed switch detection field triggers the Mini Access Detector to turn on, connect to a Wi-Fi network and send a notification — all withing a few seconds.
 
 
## Contributions
 
Contributions to the Mini Access Detector project are welcome! If you have any enhancements, bug fixes, or new features to contribute, please submit a pull request. Additionally, feel free to open issues for any questions, suggestions, or bug reports. I hope that the Mini Access Detector proves to be a valuable tool in your access monitoring endeavors. Happy detecting!
 
 
## Future Development

 - make possible for Users to set the system messages language from Telegram chat;
 - make possible for Users to change Wi-Fi networks from Telegram chat and save them into EEPROM;
 - make possible for Users to assign a name or an ID to individual access points from Telegram chat;
 - refactor unused functionality from the UniversalTelegramBot library to empty memory space.
 
 
## License

The Mini Access Detector is released under the MIT License. Please refer to the LICENSE file for more information.

 
## Regards
      
The Telegram-related functionality is possible thanks to Brian Lough's [Universal Telegram Bot](https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot) library.

The OTA functionality added using [ElegantOTA](https://github.com/ayushsharma82/ElegantOTA) as well as [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) libraries.
 

## Example of the credentials.h File

```  
#define BOTtoken    "xxxxxxxxxx:xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" // Telegram Bot Token
#define CHAT_ID     "-xxxxxxxxxxxxx"                                 // Telegram chat ID

#define OTA_PASSWORD        "1234"

#define SSID1               "wifi1_name"
#define PASSWORD1           "wifi1_password"

#define BACKUP_SSID1        "wifi2_name"
#define BACKUP_PASSWORD1    "wifi2_password"

#define BACKUP_SSID2        "wifi3_name"
#define BACKUP_PASSWORD2    "wifi3_password"
```
 
 
## Calculating Constants for the Battery Charge Function

You will need to check the following little utility:
https://github.com/RomanAlexandroff/ESP-Battery-Charge-Utility
      
It was designed to be a universal solution for battery charge level detection in ESP-based projects and has all the instructions inside of it.