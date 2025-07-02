/**
 * @file info_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 03.07.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "motor_info_message.hpp"

namespace App_messages::Cuvette_pump {
    /**
     * @brief   Response to cuvette pump info request, contains information about cuvette pump
     *          Members:
     *              uint16_t min_flowrate: Minimum flowrate of cuvette pump
     *              uint16_t max_flowrate: Maximum flowrate of cuvette pump
     */
    struct Info_response : public Motor_info_message {
        // rename data variable to flowarete
        uint16_t &min_flowrate = min;
        uint16_t &max_flowrate = max;

        Info_response(uint16_t min_speed = 0, uint16_t max_speed = 0):
            Motor_info_message(Codes::Message_type::Cuvette_pump_info_response, min_speed, max_speed)
        {}
    };
}
