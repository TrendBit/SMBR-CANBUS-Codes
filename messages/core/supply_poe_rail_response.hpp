/**
 * @file supply_poe_rail_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 20.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Contains voltage at PoE rail measured on interface module
     *          Members:
     *              float rail_poe: voltage of PoE rail in Volts
     */
    struct Supply_POE_rail_response : virtual public Float_message {
         // rename content variable to rail_poe
        float &rail_poe = content;

        explicit Supply_POE_rail_response(float voltage) :
            Float_message(voltage, Codes::Message_type::Supply_POE_rail_response)
        { }
    };
};
