/**
 * @file ojip_completed_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 10.03.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages::Fluorometer {
    /**
     * @brief Response for information if OJIP curve capture is completed
     *        Members:
     *              bool completed:    True if capture is completed, false otherwise, false before first capture
     */
    struct OJIP_completed_response: public Base_message {

        bool completed = false;

        /**
         * @brief Construct a new OJIP_completed_response object
         */
        OJIP_completed_response():
            Base_message(Codes::Message_type::Fluorometer_OJIP_completed_response)
        {}

        OJIP_completed_response(bool completed):
            Base_message(Codes::Message_type::Fluorometer_OJIP_completed_response),
            completed(completed)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != 1) {
                return false;
            }

            completed = data[0];
            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data(1);
            data[0] = completed;
            return data;
        }
    };
};
