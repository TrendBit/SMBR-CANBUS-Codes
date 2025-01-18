/**
 * @file stir.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 18.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages::Mixer {

    /**
     * @brief   Perform mixing of liquid in container with given RPM for given time
     *          Members:
     *            float rpm:   Rpm of mixer
     *            float time:  Time for which mixer should be running
     */
    struct Stir : public Base_message {
        float rpm;
        float time;

        Stir(float rpm = 0, float time = 0):
            Base_message(Codes::Message_type::Mixer_stir),
            rpm(rpm),
            time(time)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != 2 * sizeof(float)) {
                return false;
            }

            std::copy(data.begin(),
                     data.begin() + sizeof(float),
                     reinterpret_cast<uint8_t*>(&rpm));

            std::copy(data.begin() + sizeof(float),
                     data.begin() + 2 * sizeof(float),
                     reinterpret_cast<uint8_t*>(&time));

            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data(2 * sizeof(float));

            std::copy(reinterpret_cast<uint8_t*>(&rpm),
                     reinterpret_cast<uint8_t*>(&rpm) + sizeof(float),
                     data.begin());

            std::copy(reinterpret_cast<uint8_t*>(&time),
                     reinterpret_cast<uint8_t*>(&time) + sizeof(float),
                     data.begin() + sizeof(float));

            return data;
        }
    };
};
