/**
 * @file get_calibration_state_response.hpp
 * @author David Radek (david-radek(at)seznam(dot)cz)
 * @version 0.1
 * @date 10.09.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "byte_message.hpp"

namespace App_messages::Fluorometer {

    /**
     * @brief   Contains the current state of fluorometer calibration (calibrated or not)
     *          Members:
     *              bool state: false if there is no calibration curve loaded, true if there is
     */
    struct Get_calibration_state_response: public Byte_message {
        uint8_t &state = content;

        Get_calibration_state_response(bool state = false):
            Byte_message(static_cast<uint8_t>(state), Codes::Message_type::Fluorometer_get_calibration_state_response)
        {}
    };
};
