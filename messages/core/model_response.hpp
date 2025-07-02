/**
 * @file model_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 02.07.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "codes/messages/base_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Response to model request, contains model name of core module (SBC model)
     *          General format of model name is derived from CBS model name ex: RPi4B = Raspberry Pi 4 Model B
     *          Members:
     *              std::string model_name: Model name of core module, maximum length is 8 characters
     *
     */
    struct Model_response: public Base_message {
        inline static const size_t max_length = 8;

        std::string model_name;

        Model_response(std::string model_name = ""):
            Base_message(Codes::Message_type::Core_model_response),
            model_name(model_name)
        {
            this->model_name = model_name.substr(0, max_length);
        }

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            model_name = std::string(data.begin(), data.end());
            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            unsigned int length = std::min(model_name.length(), max_length);
            can_data_vector_t data;
            data.resize(length);
            std::copy(model_name.begin(), model_name.begin() + length,
                    reinterpret_cast<char*>(data.data()));
            return data;
        }
    };
};
