/**
 * @file set_max_flowrate.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 12.02.2026
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Aerator {

    /**
     * @brief   Sets max flowrate of aerator
     *          Members:
     *              float flowrate: Maximal flowrate of aerator in ml/min
     */
    struct Set_max_flowrate: public Float_message {
        // rename data variable to flowrate
        float &flowrate = content;

        Set_max_flowrate(float flowrate = 0):
            Float_message(flowrate, Codes::Message_type::Aerator_set_max_flowrate)
        {}
    };
};
