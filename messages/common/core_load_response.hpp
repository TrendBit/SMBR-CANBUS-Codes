/**
 * @file core_load_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 28.11.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages::Common {
struct Core_load_response : virtual public Base_message {
    float load = std::numeric_limits<double>::quiet_NaN();

    Core_load_response(float load = std::numeric_limits<double>::quiet_NaN()):
        Base_message(Codes::Message_type::Core_load_response),
        load(load)
    { }

    virtual bool Interpret_data(can_data_vector_t &data) override final {
        if (data.size() != sizeof(float)) {
            return false;
        }

        std::copy(data.begin(), data.end(), reinterpret_cast<uint8_t*>(&load));

        return true;
    }

    virtual can_data_vector_t Export_data() override final {
        can_data_vector_t data(sizeof(float));
        std::copy(reinterpret_cast<uint8_t *>(&load),
          reinterpret_cast<uint8_t *>(&load) + sizeof(float),
          data.begin());
        return data;
    }
};
};
