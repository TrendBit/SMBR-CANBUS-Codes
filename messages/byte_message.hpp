/**
 * @file byte_message.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 04.02.2026
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages {
    /**
     * @brief  Message containing single uint8_t value
     */
    struct Byte_message : public Base_message {
        uint8_t content;

    public:
        Byte_message(uint8_t value, Codes::Message_type type) :
            Base_message(type),
            content(value)
        {}

        uint8_t Value() const { return content; }

    virtual bool Interpret_data(can_data_vector_t &data) override final {
        if (data.size() != sizeof(uint8_t)) {
            return false;
        }

        content = data[0];

        return true;
    }

    virtual can_data_vector_t Export_data() override final {
        can_data_vector_t data(sizeof(uint8_t));
        data[0] = content;
        return data;
    }
    };

}
