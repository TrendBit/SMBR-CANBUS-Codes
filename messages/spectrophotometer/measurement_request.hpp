/**
 * @file measurement_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 13.03.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "codes/messages/base_message.hpp"

namespace App_messages::Spectrophotometer {

    /**
     * @brief Request measurement of spectrophotometer
     *          Members:
     *              uint8_t channel:     Channel of spectrophotometer which should be measured
     */
    struct Measurement_request: public Base_message {
        uint8_t channel = 0;

        explicit Measurement_request(uint8_t channel):
            Base_message(Codes::Message_type::Spectrophotometer_measurement_request),
            channel(channel)
        {}

        Measurement_request():
            Measurement_request(0)
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
