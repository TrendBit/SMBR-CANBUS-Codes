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
     *          Members:
     *              uint8_t     measurement_id          4-bit measurement id
     *              Gain        detector_gain           Gain of detector
     *              float       emitor_intensity        Intensity of emitor LED
     */
    struct Sample_request:Base_message {
        /**
         * @brief   4-bit measurement id, should be incremented with every measurement
         *          Used to determine in which measurement sequence sample belongs if any
         *          Value of 0 is reserved for undefined measurement - single samples
         */
        uint8_t measurement_id = 15;

        /**
         * @brief   Gain of detector which to use during measurement
         */
        Fluorometer_config::Gain detector_gain = Fluorometer_config::Gain::x1;

        /**
         * @brief   Intensity of emitor LED, which to use to capture
         *          Value is in range 0-1.0 mapped to 0-255
         */
        float emitor_intensity = 0.0;

        /**
         * @brief Construct a new Sample_request object
         */
        Sample_request():
            Base_message(Codes::Message_type::Fluorometer_sample_request)
        {}

        Sample_request(uint8_t id, Fluorometer_config::Gain gain, float intensity):
            Base_message(Codes::Message_type::Fluorometer_sample_request),
            measurement_id(id),
            detector_gain(gain),
            emitor_intensity(intensity)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != 2) {
                return false;
            }

            measurement_id = (data[0] & 0xf0) >> 4;
            detector_gain = static_cast<Fluorometer_config::Gain>(0x0f & data[0]);
            emitor_intensity = static_cast<float>(data[1]) / 255.0f;

            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data(1);

            data[0] = (measurement_id << 4) | (static_cast<uint8_t>(detector_gain) & 0x0f);
            data[1] = static_cast<uint8_t>(emitor_intensity * 255);

            return data;
        }
    };
};
