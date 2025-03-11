/**
 * @file ojip_retrieve_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 10.03.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Fluorometer {
    /**
     * @brief Request for information if OJIP curve capture is completed
     */
    struct OJIP_retrieve_request: public Empty_data_message {

        /**
         * @brief Construct a new OJIP_retrieve_request object
         */
        OJIP_retrieve_request():
            Base_message(Codes::Message_type::Fluorometer_OJIP_retrieve_request)
        {}
    };
};

