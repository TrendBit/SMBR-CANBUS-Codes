/**
 * @file pump_count_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 12.12.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Pumps {
    /**
     * @brief   Request for number of pumps connected to pump module
     *          Response should be sent as Pumps_pump_count_response
     */
    struct Pump_count_request: public Empty_data_message {

        Pump_count_request():
            Base_message(Codes::Message_type::Pumps_pump_count_request)
        {}
    };
};
