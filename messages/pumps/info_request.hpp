/**
 * @file info_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 04.02.2026
 */

#pragma once

#include "codes/codes.hpp"

#include "byte_message.hpp"

namespace App_messages::Pumps {

/**
 * @brief   Request for information about selected pump
 *          Response should be sent as Pumps_info_response
 *          Members:
 *              uint8_t pump_index: Index of the pump
 */
struct Info_request: public Byte_message {
    uint8_t &pump_index = content;

    explicit Info_request(uint8_t pump_index = 0):
        Byte_message(pump_index, Codes::Message_type::Pumps_info_request)
    {}
};

};
