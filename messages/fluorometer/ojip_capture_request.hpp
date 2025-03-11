/**
 * @file ojip_capture.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 10.03.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"


namespace App_messages::Fluorometer {

    /**
     * @brief   Request to capture OJIP curve from fluorometer
     *          Members:
     *              uint8_t  measurement_id      4-bit measurement id
     *              Gain     detector_gain       Gain of detector
     *              float    emitor_intensity    Intensity of emitor LED
     *              Timing   sample_timing       Sample timing
     *              uint16_t length_ms           Length of measurement in milliseconds
     *              uint16_t samples             Number of samples to capture
     */
    struct OJIP_capture_request:Base_message {
        /**
         * @brief   4-bit measurement id, should be incremented with every measurement
         *          Used to determine in which measurement sequence sample belongs
         *          Value of 0 is reserved for undefined measurement - single samples
         */
        uint8_t measurement_id;

        /**
         * @brief   Gain of detector which to use during measurement
         */
        Fluorometer_config::Gain detector_gain = Fluorometer_config::Gain::Undefined;

        /**
         * @brief   Sample timing which will be used to time capture of data (linear, logarithmic, ...)
         */
        Fluorometer_config::Timing sample_timing = Fluorometer_config::Timing::Undefined;

        /**
         * @brief   Intensity of emitor LED, which to use to capture
         *          Value is in range 0-1.0 mapped to 0-255
         */
        float emitor_intensity = 1.0;

        /**
         * @brief   Length of measurement in milliseconds, generally in range 200-4000 ms
         */
        uint16_t length_ms = 1000;

        /**
         * @brief   Number of samples to capture during measurement
         *          For 1s measurement should be around 1-2k samples
         */
        uint16_t samples = 1000;

        /**
         * @brief Construct a new OJIP_capture object
         */
        OJIP_capture_request():
            Base_message(Codes::Message_type::Fluorometer_OJIP_capture_request)
        {}

        OJIP_capture_request(uint8_t measurement_id, Fluorometer_config::Gain gain, Fluorometer_config::Timing timing, uint8_t emitor_intensity, uint16_t length_ms, uint16_t samples):
            Base_message(Codes::Message_type::Fluorometer_OJIP_capture_request),
            measurement_id(measurement_id),
            detector_gain(gain),
            sample_timing(timing),
            emitor_intensity(emitor_intensity),
            length_ms(length_ms),
            samples(samples)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != 8) {
                return false;
            }

            measurement_id = (data[0] & 0xf0) >> 4;
            detector_gain = static_cast<Fluorometer_config::Gain>(data[0] & 0x0f);
            emitor_intensity = static_cast<float>(data[1]) / 255;
            sample_timing = static_cast<Fluorometer_config::Timing>(data[2]);
            length_ms = (data[4] << 8) | data[5];
            samples = (data[6] << 8) | data[7];

            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data;
            data.resize(8);

            data[0] = (measurement_id << 4) | static_cast<uint8_t>(detector_gain);
            data[1] = emitor_intensity * 255;
            data[2] = static_cast<uint8_t>(sample_timing);
            data[3] = 0;
            data[4] = (length_ms >> 8) & 0xff;
            data[5] = length_ms & 0xff;
            data[6] = (samples >> 8) & 0xff;
            data[7] = samples & 0xff;

            return data;
        }
    };

};

