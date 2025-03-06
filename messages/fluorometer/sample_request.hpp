/**
 * @file sample_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 06.03.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"
#include "fluorometer_config.hpp"

namespace App_messages::Fluorometer {
    /**
     * @brief   Request to measure sample from fluorometer with defined gain
     */
    struct Sample_request:Base_message {

        Fluorometer_config::Gain gain = Fluorometer_config::Gain::Undefined;

        /**
         * @brief Construct a new Sample_request object
         */
        Sample_request():
            Base_message(Codes::Message_type::Fluorometer_sample_request)
        {}

        Sample_request(Fluorometer_config::Gain gain):
            Base_message(Codes::Message_type::Fluorometer_sample_request),
            gain(gain)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != 1) {
                return false;
            }

            gain = static_cast<Fluorometer_config::Gain>(data[0]);
            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data(1);
            data[0] = static_cast<uint8_t>(gain);
            return data;
        }
    };
};
