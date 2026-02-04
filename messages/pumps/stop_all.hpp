/**
 * @file stop_all.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 04.02.2026
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Pumps {
    /**
     * @brief   Stop all pumps
     */
    struct Stop_all: public Empty_data_message {
        Stop_all():
            Base_message(Codes::Message_type::Pumps_stop_all)
        {}
    };
};
