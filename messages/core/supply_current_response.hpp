/**
 * @file supply_current_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 20.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Contains current current draw of device
     *          Members:
     *              float current: current current draw of device in Amperes
     */
    struct Supply_current_response : virtual public Float_message {
         // rename data variable to current
        float &current = content;

        explicit Supply_current_response(float current) :
            Float_message(current, Codes::Message_type::Supply_current_response)
        { }
    };
};
