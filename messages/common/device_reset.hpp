/**
 * @file device_reset.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 29.10.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Common {
struct Device_reset : Empty_data_message {
    Device_reset() :
        Base_message(Codes::Message_type::Device_reset)
    { }
};
};
