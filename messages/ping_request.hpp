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
    /**
     * @brief   Sequence number of ping request, used for identification of response
     */
    uint8_t sequence_number = 0;

    Ping_request(uint8_t sequence_number = 0):
        Base_message(Codes::Message_type::Ping_request),
        sequence_number(sequence_number)
    {}

    virtual bool Interpret_data(can_data_vector_t &data) override final {
        if (data.size() != 1) {
            return false;
        }
        sequence_number = data[0];
        return true;
    }

    virtual can_data_vector_t Export_data() override final {
        can_data_vector_t data(1);
        data[0] = sequence_number;
        return data;
    }
};

};
