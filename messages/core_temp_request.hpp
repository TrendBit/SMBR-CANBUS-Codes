/**
 * @file core_temp_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 08.10.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "can_bus/app_message.hpp"
#include "empty_data_message.hpp"

namespace App_messages {
struct Core_temp_request : Empty_data_message {
    Core_temp_request() :
        Base_message(Codes::Message_type::Core_temperature_request)
    { }
};
};
