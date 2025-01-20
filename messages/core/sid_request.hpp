/**
 * @file sid_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 20.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Request for SID of device
     *          Device should respond with SID response
     */
    struct SID_request : virtual public Empty_data_message {
        SID_request() :
            Base_message(Codes::Message_type::Core_SID_request)
        { }
    };
};
