/**
 * @file measurement_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 13.03.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "codes/messages/base_message.hpp"

namespace App_messages::Spectrophotometer {

    /**
     * @brief Response for measurement of spectrophotometer
     *          Members:
     *              uint8_t     channel:        Channel of spectrophotometer which was measured
     *              float       value:          Relative value of channel
     */
    struct Measurement_response: public Base_message {
        uint8_t channel = 0;
        float relative_value = 0;
        uint16_t absolute_value = 0;


        explicit Measurement_response(uint8_t channel, float relative_value, float absolute_value):
            Base_message(Codes::Message_type::Spectrophotometer_measurement_response),
            channel(channel),
            relative_value(relative_value),
            absolute_value(absolute_value)
        {}

        Measurement_response():
            Measurement_response(0, 0 , 0)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != 7) {
                return false;
            }

            channel = data[0];
            relative_value = *reinterpret_cast<float *>(&data[1]);

            absolute_value = (data[5] << 8);
            absolute_value |= data[6] & 0xFF;

            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data(7);
            data[0] = channel;

            auto value_data = reinterpret_cast<uint8_t *>(&relative_value);
            data[1] = value_data[0];
            data[2] = value_data[1];
            data[3] = value_data[2];
            data[4] = value_data[3];

            data[5] = absolute_value >> 8;
            data[6] = absolute_value & 0xFF;

            return data;
        }
    };
};
