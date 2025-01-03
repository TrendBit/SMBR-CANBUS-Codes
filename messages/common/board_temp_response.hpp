/**
 * @file board_temp_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 03.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Common {

    /**
     * @brief   Contains temperature of module board
     *          Members:
     *              float temperature: temperature of module on board sensor
     */
    struct Board_temp_response: public Float_message {
        // rename data variable to temperature
        float &temperature = content;

        Board_temp_response(float temperature = 0):
            Float_message(temperature, Codes::Message_type::Board_temperature_response)
        {}
    };
};
