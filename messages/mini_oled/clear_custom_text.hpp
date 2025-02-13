/**
 * @file clear_custom_text.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 13.02.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Mini_OLED {
    /**
     * @brief   Request to read temperature of LED panel
     */
    struct Clear_custom_text:Empty_data_message {
        Clear_custom_text():
            Base_message(Codes::Message_type::Mini_OLED_clear_custom_text)
        {}
    };
};
