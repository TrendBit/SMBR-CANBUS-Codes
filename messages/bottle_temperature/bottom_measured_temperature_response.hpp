/**
 * @file bottom_measured_temperature_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 21.01.2025
 */

#pragma once

#include "codes/messages/float_message.hpp"

namespace App_messages::Bottle_temperature {

    /**
     * @brief   Response for measured temperature of target (bottle) from bottom thermopile sensor
     *          Members:
     *              float temperature: Current temperature measured by bottom thermopile sensor
     */
    struct Bottom_measured_temperature_response: public Float_message {
        // rename content variable to temperature
        float &temperature = content;

        Bottom_measured_temperature_response(float temperature = 0):
            Float_message(temperature, Codes::Message_type::Bottle_bottom_measured_temperature_response)
        {}
    };
};
