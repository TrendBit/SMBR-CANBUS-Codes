/**
 * @file led_get_intensity_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 19.11.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages {

struct LED_get_intensity_request : virtual public Base_message {
    /**
     * @brief   Channel of LED, which intensity will be requested
     */
    uint8_t channel = 0;

    LED_get_intensity_request(uint8_t channel = 0):
        Base_message(Codes::Message_type::LED_get_intensity_request),
        channel(channel)
    {}

    virtual bool Interpret_data(can_data_vector_t &data) override final {
        if (data.size() != 1) {
            return false;
        }
        channel = data[0];
        return true;
    }

    virtual can_data_vector_t Export_data() override final {
        can_data_vector_t data(1);
        data[0] = channel;
        return data;
    }
};

};
