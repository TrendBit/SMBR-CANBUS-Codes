/**
 * @file get_speed_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 18.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Mixer {

    /**
     * @brief   Response to request for current speed of mixer
     *          Members:
     *              float speed: Current speed of mixer in range 0-1.0
     */
    struct Get_speed_response: public Float_message {
        // rename data variable to speed
        float &speed = content;

        Get_speed_response(float speed = 0):
            Float_message(speed, Codes::Message_type::Mixer_get_speed_response)
        {}
    };
};
