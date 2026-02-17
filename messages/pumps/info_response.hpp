/**
 * @file info_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 04.02.2026
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages::Pumps {

/**
 * @brief   Response with information (limits) about selected pump
 *          Members:
 *              uint8_t pump_index: Index of the pump
 *              float max_flowrate: Maximum flow rate of the pump (transmitted as int16_t * 10)
 *              float min_flowrate: Minimum flow rate of the pump (transmitted as int16_t * 10)
 */

struct Info_response: public Base_message {
    uint8_t pump_index;
    float max_flowrate;
    float min_flowrate;

    Info_response(uint8_t pump_index = 0, float max_flowrate = 0, float min_flowrate = 0):
        Base_message(Codes::Message_type::Pumps_info_response),
        pump_index(pump_index),
        max_flowrate(max_flowrate),
        min_flowrate(min_flowrate)
    {}

    virtual bool Interpret_data(can_data_vector_t &data) override final {
        if (data.size() != sizeof(uint8_t) + sizeof(int16_t) + sizeof(int16_t)) {
            return false;
        }

        pump_index = data[0];

        int16_t temp_max_flowrate;
        std::copy(data.begin() + 1,
                    data.begin() + 1 + 1 * sizeof(int16_t),
                    reinterpret_cast<uint8_t*>(&temp_max_flowrate));
        max_flowrate = static_cast<float>(temp_max_flowrate) / 10.0f;

        int16_t temp_min_flowrate;
        std::copy(data.begin() + 1 + 1 * sizeof(int16_t),
                    data.begin() + 1 + 2 * sizeof(int16_t),
                    reinterpret_cast<uint8_t*>(&temp_min_flowrate));
        min_flowrate = static_cast<float>(temp_min_flowrate) / 10.0f;

        return true;
    }

    virtual can_data_vector_t Export_data() override final {
        can_data_vector_t data;
        data.push_back(pump_index);

        int16_t temp_max_flowrate = static_cast<int16_t>(max_flowrate * 10.0f);
        std::copy(reinterpret_cast<const uint8_t*>(&temp_max_flowrate),
                    reinterpret_cast<const uint8_t*>(&temp_max_flowrate) + sizeof(int16_t),
                    std::back_inserter(data));

        int16_t temp_min_flowrate = static_cast<int16_t>(min_flowrate * 10.0f);
        std::copy(reinterpret_cast<const uint8_t*>(&temp_min_flowrate),
                    reinterpret_cast<const uint8_t*>(&temp_min_flowrate) + sizeof(int16_t),
                    std::back_inserter(data));

        return data;
    }

};
};
