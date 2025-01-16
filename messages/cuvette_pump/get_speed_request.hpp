/**
 * @file get_speed_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 14.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Cuvette_pump {

    /**
     * @brief   Request for current speed of cuvette pump
     *          Response should be sent as Cuvette_pump_get_speed_response
     */
    struct Get_speed_request: public Empty_data_message {

        Get_speed_request():
            Base_message(Codes::Message_type::Cuvette_pump_get_speed_request)
        {}
    };
};
