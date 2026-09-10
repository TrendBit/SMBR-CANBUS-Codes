/**
 * @file get_use_calibration_response.hpp
 * @author David Radek (david-radek(at)seznam(dot)cz)
 * @version 0.1
 * @date 10.09.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "byte_message.hpp"

namespace App_messages::Fluorometer {

    /**
     * @brief   Contains the current state of fluorometer calibration usage (using calibration or not)
     *          Members:
     *              bool state: false if calibration curve is ignored and unused, true if the calibration curve will be used
     */
    struct Get_use_calibration_response: public Byte_message {
        uint8_t &state = content;

        Get_use_calibration_response(bool state = false):
            Byte_message(static_cast<uint8_t>(state), Codes::Message_type::Fluorometer_get_use_calibration_response)
        {}
    };
};
