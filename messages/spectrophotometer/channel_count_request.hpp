/**
 * @file channel_count_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 12.03.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Spectrophotometer {

    /**
     * @brief Request information about number of channels of spectrophotometer
     */
    struct Channel_count_request: public Empty_data_message {

        /**
         * @brief Construct a new Channel_count_request object
         */
        Channel_count_request():
            Base_message(Codes::Message_type::Spectrophotometer_channel_count_request)
        {}
    };
};
