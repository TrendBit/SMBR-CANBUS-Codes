/**
 * @file channel_info_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 13.03.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "codes/messages/base_message.hpp"

namespace App_messages::Spectrophotometer {

    /**
     * @brief Request information about channel of spectrophotometer
     *          Members:
     *              uint8_t channel:     Channel of spectrophotometer which should be measured
     */
    struct Channel_info_request: public Base_message {
        uint8_t channel = 0;

        explicit Channel_info_request(uint8_t channel):
            Base_message(Codes::Message_type::Spectrophotometer_channel_info_request),
            channel(channel)
        {}

        Channel_info_request():
            Channel_info_request(0)
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
