/**
 * @file calibration_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 07.04.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Fluorometer {

    /**
     * @brief Request calibration of fluorometer
     */
    struct Calibration_request: public Empty_data_message {

        /**
         * @brief Construct a new Calibration_request object
         */
        Calibration_request():
            Base_message(Codes::Message_type::Fluorometer_calibration_request)
        {}
    };
};
