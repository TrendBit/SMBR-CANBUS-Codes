/**
 * @file get_flowrate_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 18.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Aerator {

    /**
     * @brief   Request for current flowrate of aerator pump
     *          Response should be sent as Aerator_get_flowrate_response
     */
    struct Get_flowrate_request: public Empty_data_message {

        Get_flowrate_request():
            Base_message(Codes::Message_type::Aerator_get_flowrate_request)
        {}
    };
};
