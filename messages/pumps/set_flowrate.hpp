/**
 * @file set_flowrate.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 04.02.2026
 */

#pragma once

#include "codes/codes.hpp"

#include "index_float_message.hpp"

namespace App_messages::Pumps {
    /**
     * @brief   Set flow rate of pump with given index
     *          Members:
     *              uint8_t pump_index: Index of the pump to set flow rate
     *              float pump_flow_rate: Desired flow rate of the pump
     */
    struct Set_flowrate: public Index_float_message {
        /**
         * @brief   Index of the pump to set flow rate
         *          Renamed from base class member
         */
        uint8_t &pump_index = index;

        /**
         * @brief   Desired flow rate of the pump
         *          Renamed from base class member
         */
        float &flowrate = value;

        Set_flowrate(uint8_t pump_index = 0, float flowrate = 0):
            Index_float_message(pump_index, flowrate, Codes::Message_type::Pumps_set_flowrate)
        {}
    };
};
