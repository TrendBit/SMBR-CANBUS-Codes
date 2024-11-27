/**
 * @file core_load_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 28.11.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Common {
struct Core_load_request : Empty_data_message {
    Core_load_request() :
        Base_message(Codes::Message_type::Core_load_request)
    { }
};
};
