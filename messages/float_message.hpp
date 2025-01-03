/**
 * @file float_message.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 02.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages {
    /**
     * @brief   Message with float data
     */
    struct Float_message: public Base_message {
        float content;

        Float_message(float content, Codes::Message_type type):
            Base_message(type),
            content(content)
        {}

    virtual bool Interpret_data(can_data_vector_t &data) override final {
        if (data.size() != sizeof(float)) {
            return false;
        }

        std::copy(data.begin(), data.end(), reinterpret_cast<uint8_t*>(&content));

        return true;
    }

    virtual can_data_vector_t Export_data() override final {
        can_data_vector_t data(sizeof(float));
        std::copy(reinterpret_cast<uint8_t *>(&content),
          reinterpret_cast<uint8_t *>(&content) + sizeof(float),
          data.begin());
        return data;
    }
};
};
