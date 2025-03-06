/**
 * @file emitor_temperature_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 06.03.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Fluorometer {
    /**
     * @brief Request for temperature of emitor
     */
    struct Emitor_temperature_request: public Empty_data_message {

        /**
         * @brief Construct a new Emitor_temperature_request object
         */
        Emitor_temperature_request():
            Base_message(Codes::Message_type::Fluorometer_emitor_temperature_request)
        {}
    };
};
