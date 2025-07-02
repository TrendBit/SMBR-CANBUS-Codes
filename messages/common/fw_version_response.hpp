/**
 * @file fw_versions_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 02.07.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages::Common{
    /**
     * @brief   Response to firmware version request, contains firmware version (major, minor, patch)
     *          General format of version is: major.minor.patch
     *          Members:
     *              uint16_t major: Major version number
     *              uint16_t minor: Minor version number
     *              uint16_t patch: Patch version number
     */
    struct FW_version_response : virtual public Base_message {
        uint16_t major = 0;
        uint16_t minor = 0;
        uint16_t patch = 0;


        FW_version_response(uint16_t fw_major = 0, uint16_t fw_minor = 0, uint16_t fw_patch = 0):
            Base_message(Codes::Message_type::Core_fw_version_response),
            major(fw_major),
            minor(fw_minor),
            patch(fw_patch)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final{
            if (data.size() != 6) {
                return false;
            }
            major = (data[0] << 8) | data[1];
            minor = (data[2] << 8) | data[3];
            patch = (data[4] << 8) | data[5];
            return true;
        }

        virtual can_data_vector_t Export_data() override final{
            can_data_vector_t data(6);
            data[0] = (major >> 8) & 0xFF;
            data[1] = major & 0xFF;
            data[2] = (minor >> 8) & 0xFF;
            data[3] = minor & 0xFF;
            data[4] = (patch >> 8) & 0xFF;
            data[5] = patch & 0xFF;
            return data;
        }
    };
}
