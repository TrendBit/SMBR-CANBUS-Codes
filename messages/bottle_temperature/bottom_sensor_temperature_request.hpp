/**
 * @file bottom_sensor_temperature_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 21.01.2025
 */

#pragma once

#include "codes/messages/empty_data_message.hpp"

namespace App_messages::Bottle_temperature {
    /**
     * @brief   Request for temperature bottom sensor (thermopile)
     *          Response should be sent as Bottle_bottom_sensor_temperature_request
     */
    struct Bottom_sensor_temperature_request: public Empty_data_message {

        Bottom_sensor_temperature_request():
            Base_message(Codes::Message_type::Bottle_bottom_sensor_temperature_request)
        {}
    };
};
