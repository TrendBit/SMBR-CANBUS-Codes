/**
 * @file get_flowrate_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 04.02.2026
 */

#pragma once

#include "codes/codes.hpp"

#include "byte_message.hpp"

namespace App_messages::Pumps {
    /**
     * @brief   Get flowrate of pump with given index
     *          Members:
     *              uint8_t pump_index: Index of the pump to read flowrate
     */
    struct Get_flowrate_request: public Byte_message {
        uint8_t &pump_index = content;

        explicit Get_flowrate_request(uint8_t pump_index = 0):
            Byte_message(pump_index, Codes::Message_type::Pumps_get_flowrate_request)
        {}
    };
};
