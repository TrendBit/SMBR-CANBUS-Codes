/**
 * @file fw_dirty_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 02.07.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Common {
    /**
     * @brief   Request for firmware dirty state of device
     *          Device should respond with firmware dirty response based on
     *              dirty flag of git repo which build this version of firmware
     */
    struct FW_dirty_request : virtual public Empty_data_message {
        FW_dirty_request() :
            Base_message(Codes::Message_type::Core_fw_dirty_request)
        { }
    };
}
