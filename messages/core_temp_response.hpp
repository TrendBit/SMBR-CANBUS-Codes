/**
 * @file core_temp_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 08.10.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages {
struct Core_temp_response : public Base_message {
    float temperature = -273.15f;

    Core_temp_response(float temperature = -273.15f) :
        Base_message(Codes::Message_type::Core_temperature_request),
        temperature(temperature)
    { }

    virtual bool Interpret_data(can_data_vector_t &data) override final {
        if (data.size() != sizeof(float)) {
            return false;
        }

        std::copy(data.begin(), data.end(), reinterpret_cast<uint8_t*>(&temperature));

        return true;
    }

    virtual can_data_vector_t Export_data() override final {
        can_data_vector_t data(sizeof(float));
        std::copy(reinterpret_cast<uint8_t *>(&temperature),
          reinterpret_cast<uint8_t *>(&temperature) + sizeof(float),
          data.begin());
        return data;
    }
};
};
