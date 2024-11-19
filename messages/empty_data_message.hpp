/**
 * @file empty_data_message.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 08.10.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages {

/**
 * @brief  Abstract type of message which has no data, and contains only type of message
 *              All messages with similar structure will handle data in same way, no need for data processing
 *              Derived classes will only define type of message
 */
struct Empty_data_message : virtual Base_message {
    Empty_data_message() :
        Base_message(Codes::Message_type::Undefined)
    { }

    virtual bool Interpret_data(can_data_vector_t &data) override final {
        if (data.size() != 0) {
            return false;
        }

        return true;
    }

    virtual can_data_vector_t Export_data() override final {
        return {};
    }
};
};
