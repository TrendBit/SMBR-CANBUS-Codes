/**
 * @file hostname_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 20.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Response to hostname request, contains hostname of device
     *          Members:
     *              std::string hostname: Hostname of device, truncated to 8 characters
     *
     */
    struct Hostname_response : virtual public Base_message {
        /**
         * @brief   Hostname of device
         */
        std::string hostname;

        explicit Hostname_response(std::string device_hostname = ""):
            Base_message(Codes::Message_type::Core_hostname_response),
            hostname(device_hostname)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            hostname = std::string(data.begin(), data.end());
            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data;
            data.assign(reinterpret_cast<const uint8_t*>(hostname.data()),
                reinterpret_cast<const uint8_t*>(hostname.data() + hostname.size()));
            return data;
        }
    };

}
