/**
 * @file led_get_intensity.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 26.11.2024
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages::LED_panel {
    /**
     * @brief   Request to read intensity of LED channel, used when web API as refreshed and does not cache data
     */
    struct Get_intensity_request:Base_message {
    /**
     * @brief   Channel of LED controller, which is requested
     */
    uint8_t channel = 0;

    /**
     * @brief Construct a new led set intensity message
     *
     * @param channel       Channel of LED controller, which is requested
     */
    Get_intensity_request(uint8_t channel = 0):
        Base_message(Codes::Message_type::LED_get_intensity_request),
        channel(channel)
    {}

    /**
     * @brief   Convert CAN data into channel and intensity values in this message
     *
     * @param data      CAN data which should be converted into LED_get_intensity message
     * @return true     Data was successfully converted
     * @return false    Data cannot be converted into this type of message
     */
    virtual bool Interpret_data(can_data_vector_t &data) override final {
        if (data.size() != 1) {
            return false;
        }

        channel = data[0];
        return true;
    }

    /**
     * @brief   Convert LED_get_intensity message into CAN data
     *
     * @return  data   Can frame data which is generated from this message
     */
    virtual can_data_vector_t Export_data() override final {
        can_data_vector_t data(3);
        data[0] = channel;
        return data;
    }
};

};
