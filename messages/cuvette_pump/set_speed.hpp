/**
 * @file set_speed.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 14.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Cuvette_pump {

    /**
     * @brief   Sets speed of cuvette pump
     *          Members:
     *              float speed: Speed of pump in range 0-1.0
     */
    struct Set_speed: public Float_message {
        // rename data variable to speed
        float &speed = content;

        Set_speed(float speed = 0):
            Float_message(speed, Codes::Message_type::Cuvette_pump_set_speed)
        {}
    };
};
