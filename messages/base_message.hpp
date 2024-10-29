/**
 * @file base_message.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 07.10.2024
 */

#pragma once

#include "codes/codes.hpp"

#ifndef CAN_DATA_TYPE
    #define CAN_DATA_TYPE std::vector<uint8_t>
#endif

typedef CAN_DATA_TYPE can_data_vector_t;

namespace App_messages {

/**
 * @brief   Base message type, defines interface from conversion from and into Application message
 *          Type of message if defined by derived class during construction
 *          Works mostly with data of CAN frame, does not care about sender or receiver of message
 */
struct Base_message {
    /**
     * @brief   Type of message, part of CAN ID
     */
    const Codes::Message_type type = Codes::Message_type::Undefined;

    /**
     * @brief Construct a new Base_message object
     *
     * @param type  Type of message which is defined by specific message
     */
     explicit Base_message(Codes::Message_type type): type(type) {};

    /**
     * @brief   Type of message, part of CAN ID
     *
     * @return Codes::Message_type  Type of message
     */
    Codes::Message_type Type() const {
        return type;
    }

    /**
     * @brief   Convert received data from CAN frame into specific message data
     *
     * @param data      Data from CAN frame which should be converted into specific message
     * @return true     Data was successfully converted
     * @return false    Data cannot be converted into this type of message
     */
    virtual bool Interpret_data(can_data_vector_t &data) = 0;

    /**
     * @brief   Convert message specific data into CAN frame data
     *
     * @return  can_data_vector_t   Data of CAN frame
     */
    virtual can_data_vector_t Export_data() = 0;



};

};
