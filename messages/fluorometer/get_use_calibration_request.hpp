/**
 * @file get_use_calibration_request.hpp
 * @author David Radek (david-radek(at)seznam(dot)cz)
 * @version 0.1
 * @date 10.09.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Fluorometer {
    /**
     * @brief   Request to read current calibration usage state
     */
    struct Get_use_calibration_request: public Empty_data_message {
        Get_use_calibration_request():
            Base_message(Codes::Message_type::Fluorometer_get_use_calibration_request)
        {}
    };
};
