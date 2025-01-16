/**
 * @file stop.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 14.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Cuvette_pump {

    /**
     * @brief   Request to stop cuvette pump
     */
    struct Stop: public Empty_data_message {

        Stop():
            Base_message(Codes::Message_type::Cuvette_pump_stop)
        {}
    };
};
