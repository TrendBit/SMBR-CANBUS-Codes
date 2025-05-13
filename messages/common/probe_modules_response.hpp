/**
 * @file probe_modules_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 08.10.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "uid_message.hpp"

#include <vector>

namespace App_messages::Common {
struct Probe_modules_response : UID_message {

    Probe_modules_response(UID_t uid = { 0, 0, 0, 0, 0, 0}) :
        UID_message(Codes::Message_type::Probe_modules_response, uid)
    { }
};
};
