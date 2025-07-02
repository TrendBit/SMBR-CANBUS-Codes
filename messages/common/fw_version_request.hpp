/**
 * @file fw_version_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 02.07.2025
 */

#pragma once

#include "empty_data_message.hpp"

namespace App_messages::Common {
    /**
     * @brief   Request for firmware version of device
     *          Device should respond with firmware version response
     */
    struct FW_version_request : virtual public Empty_data_message {
        FW_version_request() :
            Base_message(Codes::Message_type::Core_fw_version_request)
        { }
    };
};
