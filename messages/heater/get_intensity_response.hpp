/**
 * @file get_intensity_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 03.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Heater {

    /**
     * @brief   Contains configured intensity of heater as fraction of heating or cooling power
     *          Members:
     *              float intensity: Intensity of heater, value from -1.0 (cooling) to 1.0 (heating)
     */
    struct Get_intensity_response: public Float_message {
        // rename data variable to intensity
        float &intensity = content;

        Get_intensity_response(float intensity = 0):
            Float_message(intensity, Codes::Message_type::Heater_get_intensity_response)
        {}
    };
};
