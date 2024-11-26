/**
 * @file ping_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 08.10.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages::Common {

struct Ping_response: public Ping_request {
    Ping_response(uint8_t sequence_number = 0):
        Base_message(Codes::Message_type::Ping_response),
        Ping_request(sequence_number)
    {}
};

};
