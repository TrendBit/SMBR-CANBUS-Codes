/**
 * @file get_flowrate_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 18.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Aerator {

    /**
     * @brief   Response to request for current flowrate of aerator pump
     *          Members:
     *              float flowrate: Current flowrate of pump in ml/min
     */
    struct Get_flowrate_response: public Float_message {
        // rename data variable to flowrate
        float &flowrate = content;

        Get_flowrate_response(float flowrate = 0):
            Float_message(flowrate, Codes::Message_type::Aerator_get_flowrate_response)
        {}
    };
};
