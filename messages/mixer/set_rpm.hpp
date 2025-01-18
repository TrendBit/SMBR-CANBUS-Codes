/**
 * @file set_rpm.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 18.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Mixer {

    /**
     * @brief   Sets speed of mixer in RPM
     *          Members:
     *              float rpm: Speed of mixer in RPM
     */
    struct Set_rpm: public Float_message {
        // rename data variable to rpm
        float &rpm = content;

        Set_rpm(float rpm = 0):
            Float_message(rpm, Codes::Message_type::Mixer_set_rpm)
        {}
    };
};
