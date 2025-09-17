/**
 * @file enumerator_collision.hpp
 * @author David Radek
 * @version 0.1
 * @date 14.9.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages::Common {

struct Enumerator_collision: virtual public Base_message {
    /**
     * @brief   Some module has recieved a reserve message with their own instance (collided_instance).
     */
    Codes::Instance collided_instance = Codes::Instance::Undefined;

    Enumerator_collision(Codes::Instance collided_instance = Codes::Instance::Undefined):
        Base_message(Codes::Message_type::Enumerator_collision),
        collided_instance(collided_instance)
    {}

    virtual bool Interpret_data(can_data_vector_t &data) override final {
        if (data.size() != 1) {
            return false;
        }
        collided_instance = static_cast<Codes::Instance>(data[0]);
        return true;
    }

    virtual can_data_vector_t Export_data() override final {
        can_data_vector_t data(1);
        data[0] = static_cast<uint8_t>(collided_instance);
        return data;
    }
};

};
