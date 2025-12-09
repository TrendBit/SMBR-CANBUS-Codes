/**
 * @file Enumerator_set.hpp
 * @author David Radek
 * @version 0.1
 * @date 9.12.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages::Common {

struct Enumerator_set: virtual public Base_message {
    /**
     * @brief   Module with the given UID should set its instance to target_instance.
     */
    Codes::Instance target_instance = Codes::Instance::Undefined;
    UID_t uid;

    Enumerator_set(Codes::Instance target_instance = Codes::Instance::Undefined, UID_t uid = { 0, 0, 0, 0, 0, 0}):
        Base_message(Codes::Message_type::Enumerator_set),
        target_instance(target_instance),
        uid(uid)
    {}

    virtual bool Interpret_data(can_data_vector_t &data) override final {
        if (data.size() != CANBUS_UUID_LEN + 1) {
            return false;
        }
        target_instance = static_cast<Codes::Instance>(data[0]);

        std::copy(data.begin()+1, data.end(), uid.begin());
        return true;
    }

    virtual can_data_vector_t Export_data() override final {
        can_data_vector_t data(1 + CANBUS_UUID_LEN);
        data[0] = static_cast<uint8_t>(target_instance);

        std::copy(uid.begin(), uid.end(), data.begin() + 1);
        return data;
    }
};

};
