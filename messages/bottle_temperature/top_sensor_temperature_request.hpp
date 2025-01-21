/**
 * @file top_sensor_temperature_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 21.01.2025
 */

#pragma once

#include "codes/messages/empty_data_message.hpp"

namespace App_messages::Bottle_temperature {
    /**
     * @brief   Request for temperature top sensor (thermopile)
     *          Response should be sent as Bottle_top_sensor_temperature_request
     */
    struct Top_sensor_temperature_request: public Empty_data_message {

        Top_sensor_temperature_request():
            Base_message(Codes::Message_type::Bottle_top_sensor_temperature_request)
        {}
    };
};
