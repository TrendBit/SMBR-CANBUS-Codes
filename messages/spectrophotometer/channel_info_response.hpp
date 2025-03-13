/**
 * @file channel_info_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 13.03.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "codes/messages/base_message.hpp"

namespace App_messages::Spectrophotometer {
/**
     * @brief Returns information about channel of spectrophotometer
     *          Members:
     *              uint8_t     channel:                 Channel of spectrophotometer
     *              uint16_t    central_wavelength       Instance of driver which is used for this channel
     *              uint8_t     half_sensitivity_width   Width of LED spectrum at half of maximum intensity
     */
struct Channel_info_response : public Base_message {
    uint8_t  channel = 0;
    uint16_t central_wavelength     = 0;
    uint8_t  half_sensitivity_width = 0;

    explicit Channel_info_response(uint8_t channel, uint16_t central_wavelength, uint8_t half_sensitivity_width) :
        Base_message(Codes::Message_type::Spectrophotometer_channel_info_response),
        channel(channel),
        central_wavelength(central_wavelength),
        half_sensitivity_width(half_sensitivity_width)
    { }

    Channel_info_response() :
        Channel_info_response(0, 0, 0)
    { }

    virtual bool Interpret_data(can_data_vector_t &data) override final {
        if (data.size() != 5) {
            return false;
        }

        channel = data[0];
        central_wavelength     = data[1] | (data[2] << 8);
        half_sensitivity_width = data[3];

        return true;
    }

    virtual can_data_vector_t Export_data() override final {
        can_data_vector_t data(5);
        data[0] = channel;
        data[1] = central_wavelength & 0xff;
        data[2] = central_wavelength >> 8;
        data[3] = half_sensitivity_width;
        return data;
    }
};
};
