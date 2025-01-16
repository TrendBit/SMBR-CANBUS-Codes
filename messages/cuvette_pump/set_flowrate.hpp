/**
 * @file set_flowrate.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 14.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Cuvette_pump {

    /**
     * @brief   Sets flowrate of cuvette pump
     *          Members:
     *              float flowrate: Flowrate of pump in ml/min
     */
    struct Set_flowrate: public Float_message {
        // rename data variable to flowrate
        float &flowrate = content;

        Set_flowrate(float flowrate = 0):
            Float_message(flowrate, Codes::Message_type::Cuvette_pump_set_flowrate)
        {}
    };
};
