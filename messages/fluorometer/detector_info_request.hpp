/**
 * @file detector_info_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 10.03.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Fluorometer {

    /**
     * @brief Request information about detector of fluorometer
     */
    struct Detector_temperature_request: public Empty_data_message {

        /**
         * @brief Construct a new Detector_temperature_request object
         */
        Detector_temperature_request():
            Base_message(Codes::Message_type::Fluorometer_detector_temperature_request)
        {}
    };
};
