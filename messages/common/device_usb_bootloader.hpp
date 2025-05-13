/**
 * @file device_usb_bootloader.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 29.10.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "uid_message.hpp"

namespace App_messages::Common {
struct Device_usb_bootloader : UID_message {
    Device_usb_bootloader(UID_t uid = { 0, 0, 0, 0, 0, 0}) :
        UID_message(Codes::Message_type::Device_reset, uid)
    { }
};
};
