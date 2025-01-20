/**
 * @file supply_vin_rail_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 20.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Request for VIN rail supply status
     *          Device should respond with Supply_VIN_rail_response
     */
    struct Supply_VIN_rail_request : virtual public Empty_data_message {
        Supply_VIN_rail_request() :
            Base_message(Codes::Message_type::Supply_VIN_rail_request)
        { }
    };
};
