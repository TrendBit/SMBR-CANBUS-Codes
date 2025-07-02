/**
 * @file info_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 03.07.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "motor_info_message.hpp"

namespace App_messages::Aerator {
    /**
     * @brief   Response to aerator info request, contains information about aerator pump
     *          Members:
     *              uint16_t min_flowrate: Minimum flowrate of aerator air pump
     *              uint16_t max_flowrate: Maximum flowrate of aerator air pump
     */
    struct Info_response : public Motor_info_message {
        // rename data variable to flowrate
        uint16_t &min_flowrate = min;
        uint16_t &max_flowrate = max;

        Info_response(uint16_t min_speed = 0, uint16_t max_speed = 0):
            Motor_info_message(Codes::Message_type::Aerator_info_response, min_speed, max_speed)
        {}
    };
}
