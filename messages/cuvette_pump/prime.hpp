/**
 * @file prime.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 14.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Cuvette_pump {

    /**
     * @brief   Request to prime cuvette pump
     */
    struct Prime: public Empty_data_message {

        Prime():
            Base_message(Codes::Message_type::Cuvette_pump_prime)
        {}
    };
};
