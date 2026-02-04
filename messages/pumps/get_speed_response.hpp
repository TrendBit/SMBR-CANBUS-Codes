/**
 * @file get_speed_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 04.02.2026
 */

#pragma once

#include "codes/codes.hpp"

#include "index_float_message.hpp"

namespace App_messages::Pumps {
    /**
     * @brief   Get speed of pump with given index
     *          Members:
     *              uint8_t pump_index: Index of the pump to get speed
     *              float pump_speed: Current speed of the pump in range from -1.0 to 1.0
     */
    struct Get_speed_response: public Index_float_message {
        /**
         * @brief   Index of the pump to get speed
         *          Renamed from base class member
         *
         */
        uint8_t &pump_index = index;

        /**
         * @brief   Current speed of the pump in range from -1.0 to 1.0
         *          Renamed from base class member
         */
        float &pump_speed = value;

        Get_speed_response(uint8_t pump_index = 0, float pump_speed = 0):
            Index_float_message(pump_index, pump_speed, Codes::Message_type::Pumps_get_speed_response)
        {}
    };
};
