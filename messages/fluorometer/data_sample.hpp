/**
 * @file data_sample.hpp
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
     * @brief   Response for measured sample from fluorometer
     */
    struct Data_sample: virtual public Base_message {
        /**
         * @brief   4-bit measurement id, incremented with every measurement
         *          Used to determine in which measurement sequence sample belongs
         *          Value of 0 is reserved for undefined measurement - single samples
         */
        uint8_t measurement_id;

        /**
         * @brief   Gain of detect with which was measurement captured, this could change during measurement
         */
        Fluorometer_config::Gain gain = Fluorometer_config::Gain::Undefined;

        /**
         * @brief   Intensity of emitor LED, used to determine if LED is working properly
         *          Value is in range 0-255 mapped to 0-1.0
         */
        uint8_t emitor_intensity = 0;

        /**
         * @brief   Value sampled from adc
         */
        uint16_t sample_value = 0;

        /**
         * @brief   Time at which was sample captured in microseconds during measurement
         */
        uint32_t time_us = 0;

        /**
         * @brief Construct a new Data_sample message
         */
        Data_sample():
            Base_message(Codes::Message_type::Fluorometer_sample_response)
        {}

        /**
         * @brief   Measurement number, not unique, but incrementing with every measurement sequence
         *
         * @return  uint16_t    Measurement number, 0 is reserved for undefined sequences (single samples)
         */
        uint16_t Measurement_id(){
            return measurement_id;
        }

        /**
         * @brief   Relative value (without gain adjustment) of data sample as intensity in range 0-1.0
         *          Relative to maximal excitation of detected at given gain
         *
         * @return float    Relative value of sample
         */
        float Relative_value(){
            return static_cast<float>(sample_value) / ((1<<Fluorometer_config::adc_bits)-1);
        }

        /**
         * @brief   Absolute value of sample with gain adjustment
         *
         * @return float    Absolute value of sample
         */
        float Absolute_value(){
            return Relative_value() / Fluorometer_config::gain_values.at(gain);
        }

        /**
         * @brief   Intensity of emitor used to stimulate sample
         *
         * @return float    Intensity of emitor in range 0-1.0
         */
        float Emitor_intensity(){
            return static_cast<float>(emitor_intensity) / 255;
        }

        /**
         * @brief   Time at which was sample captured in milliseconds during measurement sequence
         *
         * @return float    Time in milliseconds
         */
        float Time_ms(){
            return static_cast<float>(time_us) / 1000;
        }

        /**
         * @brief Fill structure with data parsed from can message data
         *
         * @param data      Data from can message
         * @return true     Data was successfully parsed
         * @return false    Data was not parsed
         */
        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != 8) {
                return false;
            }

            measurement_id = (data[0] & 0xf0) >> 4;

            gain = static_cast<Fluorometer_config::Gain>(data[0] & 0x0f);

            emitor_intensity = data[1];

            time_us = (data[2] << 24) | (data[3] << 16) | (data[4] << 8) | data[5];

            sample_value = (data[6] << 8) | data[7];

            return true;
        }

        /**
         * @brief   Convert data from structure into can message data
         *
         * @return can_data_vector_t      Data vector with data filled into
         */
        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data(8);

            data[0] = (measurement_id << 4) | static_cast<uint8_t>(gain);

            data[1] = emitor_intensity;

            data[2] = (time_us >> 24) & 0xff;
            data[3] = (time_us >> 16) & 0xff;
            data[4] = (time_us >> 8) & 0xff;
            data[5] = time_us & 0xff;

            data[6] = (sample_value >> 8) & 0xff;
            data[7] = sample_value & 0xff;

            return data;
        }

    };
};
