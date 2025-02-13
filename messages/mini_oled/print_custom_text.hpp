/**
 * @file print_custom_text.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 13.02.2025
 */

#pragma once

#include "base_message.hpp"

namespace App_messages::Mini_OLED {
    /**
     * @brief   Request to read temperature of LED panel
     */
struct Print_custom_text: public Base_message {
    static const size_t max_length = 8;

    std::string text;

    Print_custom_text(std::string text = ""):
        Base_message(Codes::Message_type::Mini_OLED_print_custom_text),
        text(text)
    {
        this->text = text.substr(0, max_length);
    }

    virtual bool Interpret_data(can_data_vector_t &data) override final {
        text = std::string(data.begin(), data.end());
        return true;
    }

    virtual can_data_vector_t Export_data() override final {
        uint length = std::min(text.length(), max_length);
        can_data_vector_t data;
        data.resize(length);
        std::copy(text.begin(), text.begin() + length,
                 reinterpret_cast<char*>(data.data()));
        return data;
    }
};
};
