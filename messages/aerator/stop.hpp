/**
 * @file stop.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 18.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Aerator {

    /**
     * @brief   Request to stop aerator pump
     */
    struct Stop: public Empty_data_message {

        Stop():
            Base_message(Codes::Message_type::Aerator_stop)
        {}
    };
};
