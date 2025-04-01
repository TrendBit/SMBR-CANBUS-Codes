/**
 * @file detecto_infor_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 10.03.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "codes/messages/base_message.hpp"

namespace App_messages::Fluorometer {

    /**
     * @brief   Response for information about detector of fluorometer
     *          Members:
     *              uint16_t wavelength:     Cutoff frequency of detectors high pass filter, only the built-in, do not applies to external filters
     *              uint16_t sensitivity:    Base sensitivity of sensor element (without eny gain applied)
     *              uint16_t sampling_rate:  Maximal sampling rate of detector in Hz
     */
    struct Detector_info_response: public Base_message {
        uint16_t wavelength = 700;
        uint16_t sensitivity = 1;
        uint16_t sampling_rate = 500;

        explicit Detector_info_response(uint16_t temperature, uint16_t sensitivity, uint16_t sampling_rate):
            Base_message(Codes::Message_type::Fluorometer_detector_info_response),
            wavelength(temperature),
            sensitivity(sensitivity),
            sampling_rate(sampling_rate)
        {}

        Detector_info_response():
            Detector_info_response(700, 1, 500)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != 6) {
                return false;
            }

            wavelength = data[0] << 8 | data[1];
            sensitivity = data[2] << 8 | data[3];
            sampling_rate = data[4] << 8 | data[5];

            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data(4);
            data[0] = wavelength >> 8;
            data[1] = wavelength;
            data[2] = sensitivity >> 8;
            data[3] = sensitivity;
            data[4] = sampling_rate >> 8;
            data[5] = sampling_rate;

            return data;
        }
    };
};
