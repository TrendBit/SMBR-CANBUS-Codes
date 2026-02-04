/**
 * @file get_speed_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 04.02.2026
 */

#pragma once

#include "codes/codes.hpp"

#include "byte_message.hpp"

namespace App_messages::Pumps {
    /**
     * @brief   Get speed of pump with given index
     *          Members:
     *              uint8_t pump_index: Index of the pump to get speed
     */
    struct Get_speed_request: public Byte_message {
        uint8_t &pump_index = content;

        explicit Get_speed_request(uint8_t pump_index = 0):
            Byte_message(pump_index, Codes::Message_type::Pumps_get_speed_request)
        {}
    };
};
