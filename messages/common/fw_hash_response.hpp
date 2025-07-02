/**
 * @file fw_hash_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 02.07.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages::Common {
    /**
     * @brief   Response to firmware hash request, contains firmware hash of device
     *          General format of firmware hash is 64-bit unsigned integer
     *          But should be formatted as 7+ hexadecimal digits {:07x} (with leading zeroes)
     *          If hash is longer then 7*4 bytes (more commits in repo),
     *              string length will be longer but without leading zeroes.
     *          Members:
     *              uint64_t hash: Firmware hash of device
     */
    struct FW_hash_response : virtual public Base_message {

        uint64_t hash = 0;

        FW_hash_response(uint64_t fw_hash = 0):
            Base_message(Codes::Message_type::Core_fw_hash_response),
            hash(fw_hash)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != 8) {
                return false;
            }

            hash = 0;
            for (size_t i = 0; i < 8; ++i) {
                hash <<= 8;
                hash |= data[i];
            }

            return true;

        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data(8);

            for (size_t i = 0; i < 8; ++i) {
                data[i] = (hash >> ((7 - i) * 8)) & 0xFF;
            }

            return data;
        }
    };
}
