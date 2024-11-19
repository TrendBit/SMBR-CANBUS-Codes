/**
 * @file led_set_intensity.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 07.10.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages {

/**
 * @brief   Message for setting intensity of LED, contains channel of led controller and intensity of LED
 *          For intensity is internally used uint16_t value, which is converted to float value from 0.0 to 1.0
 */
struct LED_set_intensity:Base_message {
    /**
     * @brief   Channel of LED controller, which should be set
     */
    uint8_t channel = 0;

    /**
     * @brief   Intensity of LED, value from 0.0 to 1.0
     */
    float intensity = 0.0f;

    /**
     * @brief Construct a new led set intensity message
     *
     * @param channel       Channel of LED controller, which should be set
     * @param intensity     Intensity of LED, value from 0.0 to 1.0
     */
    LED_set_intensity(uint8_t channel = 0, float intensity = 0.0f):
        Base_message(Codes::Message_type::LED_set_intensity),
        channel(channel),
        intensity(std::clamp(intensity,0.0f,1.0f))
    {}

    /**
     * @brief   Convert CAN data into channel and intensity values in this message
     *
     * @param data      CAN data which should be converted into LED_set_intensity message
     * @return true     Data was successfully converted
     * @return false    Data cannot be converted into this type of message
     */
    virtual bool Interpret_data(can_data_vector_t &data) override final {
        if (data.size() != 3) {
            return false;
        }

        channel = data[0];
        intensity = (data[1] << 8 | data[2])/static_cast<float>(std::numeric_limits<uint16_t>::max());
        return true;
    }

    /**
     * @brief   Convert LED_set_intensity message into CAN data
     *
     * @return  Application_message Application message which is converted from this LED_set_intensity message
     */
    virtual can_data_vector_t Export_data() override final {
        can_data_vector_t data(3);
        data[0] = channel;
        uint16_t intensity_u16 = static_cast<uint16_t>(intensity * std::numeric_limits<uint16_t>::max());
        data[1] = intensity_u16 >> 8;
        data[2] = intensity_u16 & 0xFF;
        return data;
    }
};

};
