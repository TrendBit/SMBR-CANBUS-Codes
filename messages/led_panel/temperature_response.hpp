/**
 * @file get_temperature_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 26.11.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "common/core_temp_response.hpp"

namespace App_messages::LED_panel {
    /**
     * @brief   Response to read temperature of LED panel
     */
    struct Temperature_response: virtual public Common::Core_temp_response {

        explicit Temperature_response(float temperature):
            Base_message(Codes::Message_type::LED_get_temperature_response),
            Core_temp_response(temperature)
        {}

        Temperature_response():
            Base_message(Codes::Message_type::LED_get_temperature_response),
            Core_temp_response(0)
        {}
    };
};
