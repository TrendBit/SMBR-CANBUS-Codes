/**
 * @file supply_type_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 20.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"


namespace App_messages::Core {
    /**
     * @brief   Request to determine type of supply connected to device
     *          Device should respond with supply type response
     */
    struct Supply_type_request : virtual public Empty_data_message {
        Supply_type_request() :
            Base_message(Codes::Message_type::Supply_type_request)
        { }
    };
};
