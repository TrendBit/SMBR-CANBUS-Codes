/**
 * @file uid_message.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 14.05.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages {
    /**
     * @brief   Message containing uid of module inside data container
     *          Message is used as template for specific messages
     */
    struct UID_message: public Base_message {
        /**
         * @brief   Unique identifier of module
         */
        UID_t uid;

        UID_message(Codes::Message_type type, UID_t uid = { 0, 0, 0, 0, 0, 0}):
            Base_message(type),
            uid(uid)
        { }

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != CANBUS_UUID_LEN) {
                return false;
            }

            std::copy(data.begin(), data.end(), uid.begin());

            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t uid_vector(uid.begin(), uid.end());
            return uid_vector;
        }

};
};
