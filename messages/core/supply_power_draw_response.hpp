/**
 * @file supply_power_draw_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 20.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Contains power draw of device
     *          Members:
     *              float power_draw: power draw of device in Watts
     */
    struct Supply_power_draw_response : virtual public Float_message {
         // rename content variable to power_draw
        float &power_draw = content;

        explicit Supply_power_draw_response(float power_draw) :
            Float_message(power_draw, Codes::Message_type::Supply_power_draw_response)
        { }
    };
};
