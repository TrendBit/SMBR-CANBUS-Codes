/**
 * @file board_temp_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 03.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Common {
struct Board_temp_request : Empty_data_message {
    Board_temp_request() :
        Base_message(Codes::Message_type::Board_temperature_request)
    { }
};
};
