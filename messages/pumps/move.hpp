/**
 * @file move.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 04.02.2026
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages::Pumps {
    /**
     * @brief   Command selected pump to move given volume of liquid with given flowrate
     *          Members:
     *              uint8_t pump_index: Index of the pump
     *              float volume: Volume of liquid to move
     *              float flowrate: Flowrate of the pump (transmitted as int16_t * 10)
     */
    struct Move: public Base_message {
        uint8_t pump_index;
        float volume;
        float flowrate;

        Move(uint8_t pump_index = 0, float volume = 0, float flowrate = 0):
            Base_message(Codes::Message_type::Pumps_move),
            pump_index(pump_index),
            volume(volume),
            flowrate(flowrate)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != sizeof(uint8_t) + sizeof(float) + sizeof(int16_t)) {
                return false;
            }

            pump_index = data[0];

            std::copy(data.begin() + 1,
                      data.begin() + 1 + sizeof(float),
                      reinterpret_cast<uint8_t*>(&volume));

            int16_t temp_flowrate;
            std::copy(data.begin() + 1 + sizeof(float),
                      data.begin() + 1 + 2 * sizeof(float),
                      reinterpret_cast<uint8_t*>(&temp_flowrate));
            flowrate = static_cast<float>(temp_flowrate) / 10.0f;

            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data;
            data.push_back(pump_index);

            std::copy(reinterpret_cast<const uint8_t*>(&volume),
                      reinterpret_cast<const uint8_t*>(&volume) + sizeof(float),
                      std::back_inserter(data));

            int16_t temp_flowrate = static_cast<int16_t>(flowrate * 10.0f);
            std::copy(reinterpret_cast<const uint8_t*>(&temp_flowrate),
                      reinterpret_cast<const uint8_t*>(&temp_flowrate) + sizeof(int16_t),
                      std::back_inserter(data));

            return data;
        }
    };
};
