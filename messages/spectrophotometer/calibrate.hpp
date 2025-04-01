/**
 * @file calibrate.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 01.04.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Spectrophotometer {

    /**
     * @brief Request to calibrate spectrophotometer
     */
    struct Calibrate: public Empty_data_message {

        /**
         * @brief Construct a new Calibrate object
         */
        Calibrate():
            Base_message(Codes::Message_type::Spectrophotometer_calibrate)
        {}
    };
};
