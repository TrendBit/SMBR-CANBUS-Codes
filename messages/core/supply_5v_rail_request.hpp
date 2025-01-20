/**
 * @file supply_5v_rail_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 20.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Request for 5V rail supply status
     *          Device should respond with Supply_5V_rail_response
     */
    struct Supply_5V_rail_request : virtual public Empty_data_message {
        Supply_5V_rail_request() :
            Base_message(Codes::Message_type::Supply_5V_rail_request)
        { }
    };
};
