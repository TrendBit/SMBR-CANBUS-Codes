/**
 * @file probe_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 08.10.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Common {
struct Probe_modules_request : Empty_data_message {
    Probe_modules_request() :
        Base_message(Codes::Message_type::Probe_modules_request)
    { }
};
};
