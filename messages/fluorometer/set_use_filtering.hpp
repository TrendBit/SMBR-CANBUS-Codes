/**
 * @file set_use_filtering.hpp
 * @author David Radek (david-radek(at)seznam(dot)cz)
 * @version 0.1
 * @date 10.09.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "byte_message.hpp"

namespace App_messages::Fluorometer {

    /**
     * @brief   Sets the current state of fluorometer filtering usage (using filtering or not)
     *          Members:
     *              bool state: false if filtering should be skipped, true if the curve data should be being filtered
     */
    struct Set_use_filtering: public Byte_message {
        uint8_t &state = content;

        Set_use_filtering(bool state = 0):
            Byte_message(static_cast<uint8_t>(state), Codes::Message_type::Fluorometer_set_use_filtering)
        {}
    };
};
