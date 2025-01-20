/**
 * @file serial_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 20.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Request for serial number of device
     *          Device should respond with serial number response
     */
    struct Serial_request : virtual public Empty_data_message {
        Serial_request() :
            Base_message(Codes::Message_type::Core_serial_request)
        { }
    };
};
