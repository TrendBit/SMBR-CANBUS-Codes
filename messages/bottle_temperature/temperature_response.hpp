/**
 * @file temperature_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 21.01.2025
 */

#pragma once

#include "codes/messages/float_message.hpp"

namespace App_messages::Bottle_temperature {

    struct Temperature_response: public Float_message {
        // rename content variable to temperature
        float &temperature = content;

        Temperature_response(float temperature = 0):
            Float_message(temperature, Codes::Message_type::Bottle_temperature_response)
        {}
    };
};
