/**
 * @file motor_info.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 03.07.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "codes/messages/base_message.hpp"

namespace App_messages{
    /**
     * @brief   Message template for motor information
     *          Contains information about motor limits, used for motor control.
     *              Units of those limits depends on specific usage of given motor.
     *          Members:
     *                uint16_t min: Minimum value of motor
     *                uint16_t max: Maximum value of motor
     */
    struct Motor_info_message: public Base_message {
        uint16_t min = 0;
        uint16_t max = 0;

        Motor_info_message(Codes::Message_type type, uint16_t min_value = 0, uint16_t max_value = 0):
            Base_message(type),
            min(min_value),
            max(max_value)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != 4) {
                return false;
            }
            min = (data[0] << 8) | data[1];
            max = (data[2] << 8) | data[3];
            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data(4);
            data[0] = (min >> 8) & 0xFF;
            data[1] = min & 0xFF;
            data[2] = (max >> 8) & 0xFF;
            data[3] = max & 0xFF;
            return data;
        }

    };

};
