/**
 * @file get_temperature_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 26.11.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::LED_panel {
    /**
     * @brief   Request to read temperature of LED panel
     */
    struct Get_temperature_request:Empty_data_message {
        Get_temperature_request():
            Base_message(Codes::Message_type::LED_get_temperature_request)
        {}
    };
};
