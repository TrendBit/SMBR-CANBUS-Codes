/**
 * @file set_intensity.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 02.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Heater {

    /**
     * @brief   Sets intensity of heater as fraction of heating or cooling power
     *          Members:
     *              float intensity: Intensity of heater, value from -1.0 (cooling) to 1.0 (heating)
     */
    struct Set_intensity: public Float_message {
        // rename data variable to intensity
        float &intensity = content;

        Set_intensity(float intensity = 0):
            Float_message(intensity, Codes::Message_type::Heater_set_intensity)
        {}
    };
};
