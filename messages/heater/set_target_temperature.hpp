/**
 * @file set_target_temperature.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 03.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Heater {

    /**
     * @brief   Set target intensity of bottle which should be reached (not temperature of heater plate)
     *          Heaters set intensity in order to reach this temperature, and automatically capture bottle temperature
     *          Members:
     *             float temperature: Target temperature of bottle, nan will disable regulation
     */
    struct Set_target_temperature: public Float_message {
        // rename data variable to intensity
        float &temperature = content;

        Set_target_temperature(float temperature = 0):
            Float_message(temperature, Codes::Message_type::Heater_set_target_temperature)
        {}
    };
};
