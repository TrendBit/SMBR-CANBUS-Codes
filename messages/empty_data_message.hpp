/**
 * @file empty_data_message.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 08.10.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "can_bus/app_message.hpp"
#include "base_message.hpp"

namespace App_messages {

/**
 * @brief  Abstract type of message which has no data, and contains only type of message
 *              All messages with similar structure will handle data in same way, no need for data processing
 *              Derived classes will only define type of message
 */
struct Empty_data_message : virtual Base_message {
    Empty_data_message() :
        Base_message(Codes::Message_type::Undefined)
    { }

    bool Interpret_app_message(Application_message &message) override final {
        if (message.Message_type() != type) {
            return false;
        }

        if (message.data.size() != 0) {
            return false;
        }

        return true;
    }

    virtual Application_message To_app_message() override final {
        Application_message message(type);
        return message;
    }
};
};
