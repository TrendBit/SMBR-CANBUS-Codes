/**
 * @file set_speed.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 14.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages::Pumps {

    /**
     * @brief   Sets speed of selected pump on pump module
     *          Members:
     *              uint8_t pump_index: Index of pump to set speed (starting from 1)
     *              float speed: Speed of pump in range from -1.0 to 1.0
     */
    struct Set_speed: public Base_message {
        /**
         * @brief   Index of pump to set speed (starting from 1)
         */
        uint8_t pump_index = 0;

        float speed = 0.0f;

        Set_speed(uint8_t pump_index = 0, float speed = 0):
            Base_message(Codes::Message_type::Cuvette_pump_set_speed),
            pump_index(pump_index),
            speed(speed)
        {}

        /**
         * @brief   Convert CAN data into pump_index and speed values in this message
         *
         * @param data      CAN data which should be converted into Cuvette_pump_set_speed message
         * @return true     Data was successfully converted
         * @return false    Data cannot be converted into this type of message
         */
        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != 5) {
                return false;
            }
            pump_index = data[0];

            std::copy(data.begin()+1, data.end(), reinterpret_cast<uint8_t*>(&speed));

            return true;
        }

        /**
         * @brief   Convert Cuvette_pump_set_speed message into CAN data
         *
         * @return  data   Can frame data which is generated from this message
         */
        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data(5);
            data[0] = pump_index;
            std::copy(reinterpret_cast<uint8_t *>(&speed),
              reinterpret_cast<uint8_t *>(&speed) + sizeof(float),
              data.begin()+1);
            return data;
        }
    };
};
