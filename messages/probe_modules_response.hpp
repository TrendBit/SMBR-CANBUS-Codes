/**
 * @file probe_modules_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 08.10.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "can_bus/app_message.hpp"
#include "base_message.hpp"

namespace App_messages {
struct Probe_modules_response : Base_message {
    etl::array<uint8_t, 6> uid;

    Probe_modules_response(etl::array<uint8_t, 6> uid = { 0, 0, 0, 0, 0, 0 }) :
        Base_message(Codes::Message_type::Probe_modules_response),
        uid(uid)
    { }

    bool Interpret_app_message(Application_message &message) override final {
        if (message.Message_type() != type) {
            return false;
        }

        if (message.data.size() != 6) {
            return false;
        }

        std::copy(message.data.begin(), message.data.begin() + message.data.size(), uid.begin());

        return true;
    }

    virtual Application_message To_app_message() override final {
        etl::vector<uint8_t, 8> uid_vector(uid.begin(), uid.end());
        Application_message message(type, uid_vector);
        return message;
    }
};
};
