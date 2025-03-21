/**
 * @file supply_current_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 20.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Request for current consumption of device
     *          Device should respond with Supply_current_response
     */
    struct Supply_current_request : virtual public Empty_data_message {
        Supply_current_request() :
            Base_message(Codes::Message_type::Supply_current_request)
        { }
    };
};
