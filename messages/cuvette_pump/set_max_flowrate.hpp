/**
 * @file set_max_flowrate.hpp
 * @author Radim Homola
 * @version 0.1
 * @date 23.01.2026
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Cuvette_pump {

    /**
     * @brief   Sets max flowrate of cuvette pump
     *          Members:
     *              float flowrate: Maximal flowrate of pump in ml/min
     */
    struct Set_max_flowrate: public Float_message {
        // rename data variable to flowrate
        float &flowrate = content;

        Set_max_flowrate(float flowrate = 0):
            Float_message(flowrate, Codes::Message_type::Cuvette_pump_set_max_flowrate)
        {}
    };
};
