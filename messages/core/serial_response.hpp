/**
 * @file serial_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 20.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Response to serial number request, contains serial number of device
     *          Members:
     *              uint32_t serial_number: Serial number of device
     *
     */
    struct Serial_response : virtual public Base_message {
        /**
         * @brief   Serial number of device
         */
        uint32_t serial_number;

        explicit Serial_response(uint32_t device_serial_number = 0):
            Base_message(Codes::Message_type::Core_serial_response),
            serial_number(device_serial_number)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != 4) {
                return false;
            }
            serial_number = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data(4);
            data[0] = serial_number >> 24;
            data[1] = serial_number >> 16;
            data[2] = serial_number >> 8;
            data[3] = serial_number & 0xFF;
            return data;
        }

    };

}
