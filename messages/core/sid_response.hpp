/**
 * @file sid_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 20.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Response to SID request, contains DIF of device (short identification - 2 bytes)
     *          Members:
     *              uint16_t sid: Short identification of device
     *
     */
    struct SID_response : virtual public Base_message {
        /**
         * @brief   Short identification 2 bytes
         */
        uint16_t sid;

        explicit SID_response(uint16_t device_SID = 0):
            Base_message(Codes::Message_type::Core_SID_response),
            sid(device_SID)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != 2) {
                return false;
            }
            sid = (data[0] << 8) | data[1];
            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data(2);
            data[0] = sid >> 8;
            data[1] = sid & 0xFF;
            return data;
        }
    };

}
