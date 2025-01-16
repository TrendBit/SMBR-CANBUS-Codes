/**
 * @file move.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 14.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"


namespace App_messages {

/**
 * @brief  Move message commands cuvette pump to move given volume of liquid with given flowrate
 *          Members:
 *            float volume:    Volume of liquid to move in ml
 *            float flowrate:  Flowrate of pump in ml/min
 */
struct Move : public Base_message {
    float volume;
    float flowrate;

    Move(float volume = 0, float flowrate = 0):
        Base_message(Codes::Message_type::Cuvette_pump_move),
        volume(volume),
        flowrate(flowrate)
    {}

    virtual bool Interpret_data(can_data_vector_t &data) override final {
        if (data.size() != 2 * sizeof(float)) {
            return false;
        }

        std::copy(data.begin(),
                 data.begin() + sizeof(float),
                 reinterpret_cast<uint8_t*>(&volume));

        std::copy(data.begin() + sizeof(float),
                 data.begin() + 2 * sizeof(float),
                 reinterpret_cast<uint8_t*>(&flowrate));

        return true;
    }

    virtual can_data_vector_t Export_data() override final {
        can_data_vector_t data(2 * sizeof(float));

        std::copy(reinterpret_cast<uint8_t*>(&volume),
                 reinterpret_cast<uint8_t*>(&volume) + sizeof(float),
                 data.begin());

        std::copy(reinterpret_cast<uint8_t*>(&flowrate),
                 reinterpret_cast<uint8_t*>(&flowrate) + sizeof(float),
                 data.begin() + sizeof(float));

        return data;
    }
};

} // namespace App_messages
