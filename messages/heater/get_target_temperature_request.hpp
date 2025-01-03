/**
 * @file get_target_temperature_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 03.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Heater {
    /**
     * @brief   Request to read configured target temperature of bottle
     */
    struct Get_target_temperature_request:Empty_data_message {
        Get_target_temperature_request():
            Base_message(Codes::Message_type::Heater_get_target_temperature_request)
        {}
    };
};
