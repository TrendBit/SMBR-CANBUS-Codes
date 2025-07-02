/**
 * @file info_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 03.07.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Cuvette_pump {

    /**
     * @brief   Request for cuvette pump information
     *          Response should be sent as Cuvette_pump_info_response
     */
    struct Info_request: public Empty_data_message {

        Info_request():
            Base_message(Codes::Message_type::Cuvette_pump_info_request)
        {}
    };
};
