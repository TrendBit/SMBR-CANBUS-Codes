/**
 * @file set_use_calibration.hpp
 * @author David Radek (david-radek(at)seznam(dot)cz)
 * @version 0.1
 * @date 10.09.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "byte_message.hpp"

namespace App_messages::Fluorometer {

    /**
     * @brief   Sets the current state of fluorometer calibration usage (using calibration or not)
     *          Members:
     *              bool state: false if calibration curve should be ignored and unused, true if the calibration curve should be used
     */
    struct Set_use_calibration: public Byte_message {
        uint8_t &state = content;

        Set_use_calibration(bool state = 0):
            Byte_message(static_cast<uint8_t>(state), Codes::Message_type::Fluorometer_set_use_calibration)
        {}
    };
};
