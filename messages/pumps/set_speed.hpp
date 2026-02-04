/**
 * @file set_speed.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 14.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "index_float_message.hpp"

namespace App_messages::Pumps {

    /**
     * @brief   Sets speed of selected pump on pump module
     *          Members:
     *              uint8_t pump_index: Index of pump to set speed (starting from 1)
     *              float speed: Speed of pump in range from -1.0 to 1.0
     */
    struct Set_speed: public Index_float_message {
        /**
         * @brief   Index of pump to set speed (starting from 1)
         */
        uint8_t &pump_index = index;

        /**
         * @brief   Speed of pump in range from -1.0 to 1.0
         */
        float &speed = value;

        Set_speed(uint8_t pump_index = 0, float speed = 0):
            Index_float_message(pump_index, speed, Codes::Message_type::Pumps_set_speed)
        {}

    };
};
