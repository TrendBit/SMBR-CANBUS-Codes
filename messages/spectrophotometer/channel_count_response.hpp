/**
 * @file channel_count_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 12.03.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "codes/messages/base_message.hpp"

namespace App_messages::Spectrophotometer {

    /**
     * @brief Response for information about number of channels of spectrophotometer
     *          Members:
     *              uint8_t channel_count:     Number of channels of spectrophotometer
     */
    struct Channel_count_response: public Base_message {
        uint8_t channel_count = 0;

        explicit Channel_count_response(uint8_t channel_count):
            Base_message(Codes::Message_type::Spectrophotometer_channel_count_response),
            channel_count(channel_count)
        {}

        Channel_count_response():
            Channel_count_response(0)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != 1) {
                return false;
            }

            channel_count = data[0];

            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data(1);
            data[0] = channel_count;
            return data;
        }
    };
};
