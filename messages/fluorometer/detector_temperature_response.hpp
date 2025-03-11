/**
 * @file detector_temperature_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 10.03.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "codes/messages/float_message.hpp"

namespace App_messages::Fluorometer {

    /**
     * @brief   Response for measured temperature of detector
     *          Members:
     *              float temperature: Current temperature measured next to detector IR PIN photodiode
     *
     */
    struct Detector_temperature_response: public Float_message {
        // rename content variable to temperature
        float &temperature = content;


        explicit Detector_temperature_response(float temperature = 0):
            Float_message(temperature, Codes::Message_type::Fluorometer_detector_temperature_response)
        {}

        Detector_temperature_response():
            Detector_temperature_response(0)
        {}
    };
};
