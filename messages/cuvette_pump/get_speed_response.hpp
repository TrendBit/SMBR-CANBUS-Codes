/**
 * @file get_speed_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 14.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Cuvette_pump {

    /**
     * @brief   Response to request for current speed of cuvette pump
     *          Members:
     *              float speed: Current speed of pump in range -1.0 to 1.0
     */
    struct Get_speed_response: public Float_message {
        // rename data variable to speed
        float &speed = content;

        Get_speed_response(float speed = 0):
            Float_message(speed, Codes::Message_type::Cuvette_pump_get_speed_response)
        {}
    };
};
