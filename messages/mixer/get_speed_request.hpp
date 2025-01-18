/**
 * @file get_speed_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 18.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Mixer {

    /**
     * @brief   Request for current speed of mixer
     *          Response should be sent as Mixer_get_speed_response
     */
    struct Get_speed_request: public Empty_data_message {

        Get_speed_request():
            Base_message(Codes::Message_type::Mixer_get_speed_request)
        {}
    };
};
