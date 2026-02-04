/**
 * @file stop.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 04.02.2026
 */

#pragma once

#include "codes/codes.hpp"

#include "byte_message.hpp"

namespace App_messages::Pumps {
    /**
     * @brief   Stop pump with given index
     *          Members:
     *              uint8_t pump_index: Index of the pump to stop
     */
    struct Stop: public Byte_message {
        uint8_t &pump_index = content;

        Stop(uint8_t pump_index = 0):
            Byte_message(pump_index, Codes::Message_type::Pumps_stop)
        {}
};
};
