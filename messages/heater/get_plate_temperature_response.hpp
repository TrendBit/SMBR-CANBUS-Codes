/**
 * @file get_plate_temperature_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 03.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Heater {

    /**
     * @brief   Contains temperature of heater plate (heatspreader)
     *          Members:
     *              float temperature: temperature of heater plate (heatspreader)
     */
    struct Get_plate_temperature_response: public Float_message {
        // rename data variable to temperature
        float &temperature = content;

        Get_plate_temperature_response(float temperature = 0):
            Float_message(temperature, Codes::Message_type::Heater_get_plate_temperature_response)
        {}
    };
};
