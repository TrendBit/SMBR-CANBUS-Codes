/**
 * @file get_intensity_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 26.11.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

#include "set_intensity.hpp"

namespace App_messages::LED_panel {
    /**
     * @brief Same structure and data handling as Set_intensity, but with different message type
     */
    struct Get_intensity_response: public Set_intensity {

    /**
     * @brief Construct a new led get intensity response message
     *
     * @param channel       Channel of LED controller, which was requested
     * @param intensity     Intensity of LED, value from 0.0 to 1.0
     */
    Get_intensity_response(uint8_t channel = 0, float intensity = 0.0f):
        Base_message(Codes::Message_type::LED_get_intensity_response),
        Set_intensity(channel, intensity)
    {}
};

};
