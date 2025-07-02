/**
 * @file fw_dirty_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 02.07.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages::Common {
    /**
     * @brief   Response to firmware dirty request, contains information if firmware is dirty (modified)
     *          Device responds based on dirty flag of git repo which build this version of firmware
     *          Members:
     *              bool dirty: True if firmware is dirty, false otherwise
     */
    struct FW_dirty_response : virtual public Base_message {
        bool dirty = false;

        FW_dirty_response(bool is_dirty = false):
            Base_message(Codes::Message_type::Core_fw_dirty_response),
            dirty(is_dirty)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != 1) {
                return false;
            }
            dirty = data[0] != 0;
            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data(1);
            data[0] = dirty ? 1 : 0;
            return data;
        }
    };
}
