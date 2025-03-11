/**
 * @file sample_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 06.03.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "data_sample.hpp"

namespace App_messages::Fluorometer {
    /**
     * @brief   Response for measured sample from fluorometer
     *          Message is derived from Data_sample
     *          Time should always be set to zero
     */
    struct Sample_response: virtual public Data_sample {

        /**
         * @brief Construct a new Sample_response object
         */
        Sample_response():
            Base_message(Codes::Message_type::Fluorometer_sample_response),
            Data_sample()
        {}

    };
};
