/**
 * @file ping_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 08.10.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "can_bus/app_message.hpp"
#include "base_message.hpp"

namespace App_messages {

struct Ping_request: virtual public Base_message {
    uint8_t sequence_number = 0;

    Ping_request(uint8_t sequence_number = 0):
        Base_message(Codes::Message_type::Ping_request),
        sequence_number(sequence_number)
    {}

    bool Interpret_app_message(Application_message &message) override final{
        if (message.Message_type() != type){
            return false;
        }

        if (message.data.size() != 1) {
            return false;
        }

        sequence_number = message.data[0];

        return true;
    }

    virtual Application_message To_app_message() override final {
        etl::vector<uint8_t, 8> data(1);
        data[0] = sequence_number;
        Application_message message(type, data);
        return message;
    }
};

};
