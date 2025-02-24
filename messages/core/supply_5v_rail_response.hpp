/**
 * @file supply_5v_rail_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 20.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Contains voltage at 5V rail measured on interface module
     *          Members:
     *              float rail_5v: voltage of 5V rail in Volts
     */
    struct Supply_5V_rail_response : virtual public Float_message {
         // rename content variable to rail_5v
        float &rail_5v = content;

        explicit Supply_5V_rail_response(float voltage) :
            Float_message(voltage, Codes::Message_type::Supply_5V_rail_response)
        { }

        Supply_5V_rail_response() :
            Float_message(0, Codes::Message_type::Supply_5V_rail_response)
        { }
    };
};
