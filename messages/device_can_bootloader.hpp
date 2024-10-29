/**
 * @file device_can_bootloader.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 29.10.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "can_bus/app_message.hpp"
#include "empty_data_message.hpp"

namespace App_messages {
struct Device_can_bootloader : Empty_data_message {
    Device_can_bootloader() :
        Base_message(Codes::Message_type::Device_can_bootloader)
    { }
};
};
