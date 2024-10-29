/**
 * @file probe_modules_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 08.10.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "can_bus/app_message.hpp"
#include "base_message.hpp"

#include <vector>

#ifndef CANBUS_UUID_LEN
    #define CANBUS_UUID_LEN       6
#endif

namespace App_messages {
struct Probe_modules_response : Base_message {
    /**
     * @brief   Unique identifier of module, which is responding to probe request
     */
    std::array<uint8_t, CANBUS_UUID_LEN> uid;

    Probe_modules_response(std::array<uint8_t, CANBUS_UUID_LEN> uid = { 0, 0, 0, 0, 0, 0}) :
        Base_message(Codes::Message_type::Probe_modules_response),
        uid(uid)
    { }

    virtual bool Interpret_data(can_data_vector_t &data) override final {
        if (data.size() != 6) {
            return false;
        }

        std::copy(data.begin(), data.begin() + data.size(), uid.begin());

        return true;
    }

    virtual can_data_vector_t Export_data() override final {
        can_data_vector_t uid_vector(uid.begin(), uid.end());
        return uid_vector;
    }
};
};
