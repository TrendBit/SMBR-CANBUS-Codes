/**
 * @file hw_version_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 02.07.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages::Common {
    /**
     * @brief   Response to hardware version request, contains hardware version of module
     *          General format of version is: major.minor
     *          Members:
     *              uint16_t major: Major version number
     *              uint16_t minor: Minor version number
     */
    struct HW_version_response : virtual public Base_message {
        uint16_t major = 0;
        uint16_t minor = 0;

        HW_version_response(uint16_t hw_major = 0, uint16_t hw_minor = 0):
            Base_message(Codes::Message_type::Core_hw_version_response),
            major(hw_major),
            minor(hw_minor)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != 4) {
                return false;
            }
            major = (data[0] << 8) | data[1];
            minor = (data[2] << 8) | data[3];
            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data(4);
            data[0] = (major >> 8) & 0xFF;
            data[1] = major & 0xFF;
            data[2] = (minor >> 8) & 0xFF;
            data[3] = minor & 0xFF;
            return data;
        }
    };
}
