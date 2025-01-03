/**
 * @file get_target_temperature_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @brief
 * @version 0.1
 * @date 03.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Heater {

    /**
     * @brief   Contains configured target temperature of bottle
     *          Members:
     *              float temperature: Target temperature of bottle, nan means disabled regulation (no target temperature set)
     */
    struct Get_target_temperature_response: public Float_message {
        // rename data variable to temperature
        float &temperature = content;

        Get_target_temperature_response(float temperature = 0):
            Float_message(temperature, Codes::Message_type::Heater_get_target_temperature_response)
        {}
    };
};
