/**
 * @file info_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 03.07.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Mixer {

    /**
     * @brief   Request for mixer information
     *          Response should be sent as Mixer_info_response
     */
    struct Info_request: public Empty_data_message {

        Info_request():
            Base_message(Codes::Message_type::Mixer_info_request)
        {}
    };
};
