/**
 * @file hostname_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 20.01.2025
 */

#pragma once

#include "empty_data_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Request for hostname of device
     *          Device should respond with hostname response
     */
    struct Hostname_request : virtual public Empty_data_message {
        Hostname_request() :
            Base_message(Codes::Message_type::Core_hostname_request)
        { }
    };
};
