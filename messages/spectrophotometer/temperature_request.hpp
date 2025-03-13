/**
 * @file temperature_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 13.03.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "codes/messages/empty_data_message.hpp"

namespace App_messages::Spectrophotometer {

    /**
     * @brief   Request for temperature of spectrophotometer
     */
    struct Temperature_request: public Empty_data_message {

        Temperature_request():
            Base_message(Codes::Message_type::Spectrophotometer_temperature_request)
        {}
    };
};
