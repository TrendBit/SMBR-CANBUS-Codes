/**
 * @file info_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 03.07.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "motor_info_message.hpp"

namespace App_messages::Mixer {
    /**
     * @brief   Response to mixer info request, contains information about mixer speed limits
     *          Members:
     *              uint16_t min_rpm: Minimum RPM of mixer
     *              uint16_t max_rpm: Maximum RPM of mixer
     */
    struct Info_response : public Motor_info_message {
        // rename data variable to rpm
        uint16_t &min_rpm = min;
        uint16_t &max_rpm = max;

        Info_response(uint16_t min_value = 0, uint16_t max_value = 0):
            Motor_info_message(Codes::Message_type::Mixer_info_response, min_value, max_value)
        {}
    };
}
