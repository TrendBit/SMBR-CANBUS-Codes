/**
 * @file get_flowrate_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 04.02.2026
 */

#pragma once

#include "codes/codes.hpp"

#include "index_float_message.hpp"

namespace App_messages::Pumps {
    /**
     * @brief   Get flowrate response for pump with given index
     *          Members:
     *              uint8_t pump_index: Index of the pump
     *              float flowrate: Flowrate of the pump
     */
    struct Get_flowrate_response: public Index_float_message {
        /**
         * @brief   Index of the pump to get speed
         *          Renamed from base class member
         */
        uint8_t &pump_index = index;

        /**
         * @brief   Current flowrate of the pump
         *          Renamed from base class member
         */
        float &flowrate = value;

        explicit Get_flowrate_response(uint8_t pump_index, float flowrate):
            Index_float_message(pump_index, flowrate, Codes::Message_type::Pumps_get_flowrate_response)
        {}
    };
};
