/**
 * @file set_max_flowarate.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 12.02.2026
 */

#pragma once

#include "codes/codes.hpp"

#include "index_float_message.hpp"

namespace App_messages::Pumps {
    /**
     * @brief   Set calibrated maximum flow rate of pump with given index
     *          Members:
     *              uint8_t pump_index: Index of the pump to set calibrated flow rate
     *              float max_flow_rate: Calibrated flowrate at max speed
     */
    struct Set_max_flowrate: public Index_float_message {
        /**
         * @brief   Index of the pump to set flow rate
         *          Renamed from base class member
         */
        uint8_t &pump_index = index;

        /**
         * @brief   Desired flow rate of the pump
         *          Renamed from base class member
         */
        float &max_flow_rate = value;

        Set_max_flowrate(uint8_t pump_index = 0, float max_flow_rate = 0):
            Index_float_message(pump_index, max_flow_rate, Codes::Message_type::Pumps_set_max_flowrate)
        {}
    };
};
