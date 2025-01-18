/**
 * @file get_rpm_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 18.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Mixer {

    /**
     * @brief   Response to request for current speed of mixer in RPM
     *          Members:
     *              float rpm: Current speed of mixer in RPM
     */
    struct Get_rpm_response: public Float_message {
        // rename data variable to rpm
        float &rpm = content;

        Get_rpm_response(float rpm = 0):
            Float_message(rpm, Codes::Message_type::Mixer_get_rpm_response)
        {}
    };
};
