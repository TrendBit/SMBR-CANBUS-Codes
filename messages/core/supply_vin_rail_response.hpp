/**
 * @file supply_vin_rail_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 20.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "float_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Contains voltage at VIN rail measured on interface module
     *          Members:
     *              float rail_vin: voltage of VIN rail (12V input from power supply) in Volts
     */
    struct Supply_VIN_rail_response : virtual public Float_message {
         // rename data variable to rail_vin
        float &rail_vin = content;

        explicit Supply_VIN_rail_response(float voltage) :
            Float_message(voltage, Codes::Message_type::Supply_VIN_rail_response)
        { }
    };
};
