/**
 * @file pump_count_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 12.12.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "byte_message.hpp"

namespace App_messages::Pumps {
    /**
     * @brief   Response with number of pumps connected to pump module
     */
    struct Pump_count_response: public Byte_message {
        uint8_t &pump_count = content;

        Pump_count_response(uint8_t pump_count):
            Byte_message(pump_count, Codes::Message_type::Pumps_pump_count_response)
        {}
};
};
