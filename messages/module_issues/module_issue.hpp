#pragma once

#include "codes/codes.hpp"
#include "base_message.hpp"
#include "issue_enum.hpp"

namespace App_messages::Module_issue {

/**
 * @brief CAN module issue report
 *
 * CAN Header:
 *   - Message_type: 0xe00 (Module_issue)
 *
 * CAN Payload (max 8B):
 *   [0]   error_type (uint8_t 0-255)
 *   [1]   severity   (uint8_t 0-255)
 *   [2-5] float value (32bit)
 */
struct Module_issue : virtual public Base_message {
    uint8_t error_type = 0;
    uint8_t severity   = 0;
    float   value      = 0.0f;

    Module_issue(uint8_t error_type = 0,
                 uint8_t severity = 0,
                 float value = 0.0f) :
        Base_message(Codes::Message_type::Module_issues),
        error_type(error_type),
        severity(severity),
        value(value)
    { }

    Module_issue(IssueType issue,
                 Severity severity,
                 float value = 0.0f) :
        Base_message(Codes::Message_type::Module_issues),
        error_type(static_cast<uint8_t>(issue)),
        severity(static_cast<uint8_t>(severity)),
        value(value)
    { }

    virtual bool Interpret_data(can_data_vector_t &data) override final {
        if (data.size() < 6) {  
            return false;
        }

        error_type = data[0];
        severity   = data[1];

        std::copy(data.begin() + 2,
                  data.begin() + 2 + sizeof(float),
                  reinterpret_cast<uint8_t*>(&value));

        return true;
    }

    virtual can_data_vector_t Export_data() override final {
        can_data_vector_t data(2 + sizeof(float));

        data[0] = error_type;
        data[1] = severity;

        std::copy(reinterpret_cast<uint8_t*>(&value),
                  reinterpret_cast<uint8_t*>(&value) + sizeof(float),
                  data.begin() + 2);

        return data;
    }
};

};
