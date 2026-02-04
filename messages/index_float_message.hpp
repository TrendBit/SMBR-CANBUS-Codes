/**
 * @file index_float_message.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 04.02.2026
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages {
    /**
     * @brief   Universal message including byte and float (index and value)
     *          Members:
     *              uint8_t index: Index of channel/device/anything
     *              float value: Value associated with the index
     */
    struct Index_float_message: public Base_message {
        uint8_t index;
        float value ;

        /**
         * @brief Construct a new Index_float_message object
         *
         * @param index Index
         * @param value Values
         * @param type Derived message type
         */
        explicit Index_float_message(uint8_t index, float value, Codes::Message_type type):
            Base_message(type),
            index(index),
            value(value)
        {}

        /**
         * @brief  Convert CAN data payload into message payload (index and value)
         *
         * @param data
         * @return true
         * @return false
         */
        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != sizeof(uint8_t) + sizeof(float)) {
                return false;
            }
            index = data[0];
            std::copy(data.begin()+1, data.end(), reinterpret_cast<uint8_t*>(&value));
            return true;
        }

        /**
         * @brief   Convert message payload into CAN data payload
         *
         * @return  data   Can frame data which is generated from this message
         */
        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data(sizeof(uint8_t) + sizeof(float));
            data[0] = index;
            std::copy(reinterpret_cast<uint8_t *>(&value),
              reinterpret_cast<uint8_t *>(&value) + sizeof(float),
              data.begin() + 1);
            return data;
        }
    };
};
