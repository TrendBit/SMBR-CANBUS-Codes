/**
 * @file model_request.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 02.07.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "empty_data_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Request for model of core module (SBC model)
     *          Device should respond with model response
     */
    struct Model_request : virtual public Empty_data_message {
        Model_request() :
            Base_message(Codes::Message_type::Core_model_request)
        { }
    };
}
