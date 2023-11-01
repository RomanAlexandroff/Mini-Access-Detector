/* ********************************************************************************************** */
/*                                                                                                */
/*   IoT  Name  Badge  ESP32-C3                                        :::::::::        :::       */
/*   power_down_recovery.h                                            :+:    :+:     :+: :+:      */
/*                                                                   +:+    +:+    +:+   +:+      */
/*   By: Roman Alexandrov <r.aleksandroff@gmail.com>                +#++:++#:    +#++:++#++:      */
/*                                                                 +#+    +#+   +#+     +#+       */
/*   Created: 2023/09/27 18:14:16                                 #+#    #+#   #+#     #+#        */
/*   Updated: 2023/10/21 17:05:00                                ###    ###   ###     ###         */
/*                                                                                                */
/*                                                                                                */
/*   This function detects lose of power and resets important variables                           */
/*                                                                                                */
/* ********************************************************************************************** */

void  ft_power_down_recovery(void)
{
    esp_reset_reason_t         reason;

    reason = esp_reset_reason();
    switch (reason)
    {
        case ESP_RST_POWERON:
            bot.sendMessage(CHAT_ID, "Hello! I am the Mini Access Detector. I am ON and ready for work!", "");
            DEBUG_PRINTF("\nReset reason: Power-on\n", "");
            break;
        case ESP_RST_BROWNOUT:
            bot.sendMessage(CHAT_ID, "Huh...!? Hello...? Oh! Sorry! It seems that I've fainted for a second there! Something is wrong with my power source...", "");
            DEBUG_PRINTF("\nReset reason: Brown-out reset!\n", "");
            ft_delay(3000);
            break;
        case ESP_RST_SW:
            bot.sendMessage(CHAT_ID, ("I've successfully rebooted. Current software version " + String(SOFTWARE_VERSION)), "");
            DEBUG_PRINTF("\nReset reason: Software reset. Current software version " + String(SOFTWARE_VERSION) + "\n", "");
            ft_delay(1000);
            bot.sendMessage(CHAT_ID, "Is there anything else I can do for you?", "");
            ft_check_incomming_messages(0);
            break;
        case ESP_RST_PANIC:
            bot.sendMessage(CHAT_ID, "Don't panic, but my Core processor has just panicked!", "");
            ft_delay(3000);
            bot.sendMessage(CHAT_ID, "You were trying to update me, weren't you? Well, let's try again", "");
            ft_delay(2000);
            DEBUG_PRINTF("\nReset reason: Panic/exception reset\n", "");
            ft_check_incomming_messages(ft_ota_mode(CHAT_ID));
            ft_go_to_sleep(0);
            break;
    }
}
