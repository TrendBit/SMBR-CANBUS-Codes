/**
 * @file ip_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 20.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include <array>

#include "base_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Response to IP address request, contains IP address of device
     *          Members:
     *              std::array<uint8_t, 4> IP_address: IP address of device
     *
     */
    struct IP_address_response : virtual public Base_message {
        /**
         * @brief   IP address of device
         */
        std::array<uint8_t, 4> IP_address;

        explicit IP_address_response(std::array<uint8_t, 4> device_IP_address = {0,0,0,0}):
            Base_message(Codes::Message_type::Core_IP_response),
            IP_address(device_IP_address)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != 4) {
                return false;
            }
            IP_address[0] = data[0];
            IP_address[1] = data[1];
            IP_address[2] = data[2];
            IP_address[3] = data[3];
            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data(4);
            data[0] = IP_address[0];
            data[1] = IP_address[1];
            data[2] = IP_address[2];
            data[3] = IP_address[3];
            return data;
        }

    };

}
