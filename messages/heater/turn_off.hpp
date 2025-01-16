/**
 * @file turn_off.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 03.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Heater {
    /**
     * @brief   Request to turn off heater
     */
    struct Heater_turn_off:Empty_data_message {
        Heater_turn_off():
            Base_message(Codes::Message_type::Heater_turn_off)
        {}
    };
};
