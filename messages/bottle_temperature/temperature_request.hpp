/**
 * @file temperature_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 21.01.2025
 */

#pragma once

#include "codes/messages/empty_data_message.hpp"

namespace App_messages::Bottle_temperature {
    /**
     * @brief   Request for current temperature of bottle
     *          Response should be sent as Bottle_temperature_response
     *          This temperature can be compiled from several sensors
     */
    struct Temperature_request: public Empty_data_message {

        Temperature_request():
            Base_message(Codes::Message_type::Bottle_temperature_request)
        {}
    };
};
