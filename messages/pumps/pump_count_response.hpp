/**
 * @file pump_count_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 12.12.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages::Pumps {
    /**
     * @brief   Response with number of pumps connected to pump module
     */
    struct Pump_count_response: public Base_message {
        uint8_t pump_count;

        Pump_count_response(uint8_t pump_count):
            Base_message(Codes::Message_type::Pumps_pump_count_response),
            pump_count(pump_count)
        {}

    virtual bool Interpret_data(can_data_vector_t &data) override final {
        if (data.size() != sizeof(uint8_t)) {
            return false;
        }

        pump_count = data[0];

        return true;
    }

    virtual can_data_vector_t Export_data() override final {
        can_data_vector_t data(sizeof(uint8_t));
        data[0] = pump_count;
        return data;
    }
};
};
