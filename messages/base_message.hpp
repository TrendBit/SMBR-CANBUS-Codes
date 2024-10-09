/**
 * @file base_message.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 07.10.2024
 */

#pragma once

#include "codes/codes.hpp"
#include "message_config.hpp"
#include "can_bus/app_message.hpp"

namespace App_messages {

/**
 * @brief   Base message type, defines interface from conversion from and into Application message
 *          Type of message if defined by derived class during construction
 *          Works mostly with data of CAN frame, does not care about sender or receiver of message
 */
struct Base_message {
    /**
     * @brief   Type of message, part of CAN ID
     */
    const Codes::Message_type type = Codes::Message_type::Undefined;

    /**
     * @brief Construct a new Base_message object
     *
     * @param type  Type of message which is defined by specific message
     */
     explicit Base_message(Codes::Message_type type): type(type) {};

    /**
     * @brief   Convert received Application message into derived class
     *
     * @param message   Application message which should be converted into specific message
     * @return true     Message was successfully converted
     * @return false    Message cannot be converted into this type of message
     */
    virtual bool Interpret_app_message(Application_message &message) = 0;

    /**
     * @brief   Convert message into Application message
     *
     * @return Application_message  Application message which is converted from this specific message
     */
    virtual Application_message To_app_message() = 0;

    Codes::Message_type Message_type() const {
        return type;
    }

};

};
