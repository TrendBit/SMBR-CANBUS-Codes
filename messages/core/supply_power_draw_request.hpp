/**
 * @file supply_power_draw_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 20.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Request for power draw of device
     *          Device should respond with Supply_power_draw_response
     */
    struct Supply_power_draw_request : virtual public Empty_data_message {
        Supply_power_draw_request() :
            Base_message(Codes::Message_type::Supply_power_draw_request)
        { }
    };
};
