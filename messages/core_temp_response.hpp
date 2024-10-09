/**
 * @file core_temp_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 08.10.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "can_bus/app_message.hpp"
#include "base_message.hpp"

namespace App_messages {
struct Core_temp_response : public Base_message {
    float temperature = -273.15f;

    Core_temp_response(float temperature = -273.15f) :
        Base_message(Codes::Message_type::Core_temperature_request),
        temperature(temperature)
    { }

    bool Interpret_app_message(Application_message &message) override final {
        if (message.Message_type() != type) {
            return false;
        }

        if (message.data.size() != sizeof(float)) {
            return false;
        }

        std::copy(message.data.begin(), message.data.end(), reinterpret_cast<uint8_t*>(&temperature));

        return true;
    }

    virtual Application_message To_app_message() override final {
        can_data data(sizeof(float));
        std::copy(reinterpret_cast<uint8_t *>(&temperature),
          reinterpret_cast<uint8_t *>(&temperature) + sizeof(float),
          data.begin());
        Application_message message(type, data);
        return message;
    }
};
};
