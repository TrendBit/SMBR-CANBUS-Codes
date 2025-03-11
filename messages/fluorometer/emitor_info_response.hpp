/**
 * @file emitor_info_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 10.03.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "codes/messages/base_message.hpp"

namespace App_messages::Fluorometer {

    /**
     * @brief Response for information about emitor of fluorometer
     *        Members:
     *              uint16_t wavelength:     Peak Wavelength of emitor LED
     *              uint16_t power_output:   Intensity of emitor LED in mW
     */
    struct Emitor_info_response: public Base_message {
        uint16_t wavelength = 525;
        uint16_t power_output = 10000;

        explicit Emitor_info_response(uint16_t wavelength, uint16_t power_output):
            Base_message(Codes::Message_type::Fluorometer_emitor_info_response),
            wavelength(wavelength),
            power_output(power_output)
        {}

        Emitor_info_response():
            Emitor_info_response(0, 0)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != 4) {
                return false;
            }

            wavelength = data[0] << 8 | data[1];
            power_output = data[2] << 8 | data[3];

            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data(4);
            data[0] = wavelength >> 8;
            data[1] = wavelength;
            data[2] = power_output >> 8;
            data[3] = power_output;
            return data;
        }
    };
};
