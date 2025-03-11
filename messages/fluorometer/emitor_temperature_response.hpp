/**
 * @file emitor_temperature_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 06.03.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "codes/messages/float_message.hpp"

namespace App_messages::Fluorometer {
    /**
     * @brief Response for measured temperature of emitor
     *        Members:
     *          float temperature: Current temperature measured on emitor LED
     */
    struct Emitor_temperature_response: public Float_message {
        // rename content variable to temperature
        float &temperature = content;

        explicit Emitor_temperature_response(float temperature = 0):
            Float_message(temperature, Codes::Message_type::Fluorometer_emitor_temperature_response)
        {}

        Emitor_temperature_response():
            Emitor_temperature_response(0)
        {}
    };
};
