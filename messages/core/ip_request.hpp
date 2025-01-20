/**
 * @file ip_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 20.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Request for IP address of device
     *          Device should respond with IP address response
     */
    struct IP_address_request : virtual public Empty_data_message {
        IP_address_request() :
            Base_message(Codes::Message_type::Core_IP_request)
        { }
    };
};
