/**
 * @file hw_version_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 02.07.2025
 */

#pragma once

#include "empty_data_message.hpp"

namespace App_messages::Common {
    /**
     * @brief   Request for hardware version of module
     *          Device should respond with hardware version response
     */
    struct HW_version_request : virtual public Empty_data_message {
        HW_version_request() :
            Base_message(Codes::Message_type::Core_hw_version_request)
        { }
    };
};
