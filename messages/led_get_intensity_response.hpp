/**
 * @file led_get_intensity_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 19.11.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "led_set_intensity.hpp"

namespace App_messages {

struct LED_get_intensity_response: virtual public LED_set_intensity {

    LED_get_intensity_response(uint8_t channel = 0, float intensity = 0.0f):
        Base_message(Codes::Message_type::LED_get_intensity_response),
        channel(channel),
        intensity(std::clamp(intensity,0.0f,1.0f))
    {}

};
