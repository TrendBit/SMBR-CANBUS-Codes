#pragma once

#include "codes/codes.hpp"
#include "base_message.hpp"
#include "float_message.hpp"
#include "issue_enum.hpp"

namespace App_messages::Module_issue {

/**
 * @brief CAN module issue report
 *
 * CAN Header:
 *   - Message_type: 0xe00 (Module_issue)
 *
 * CAN Payload (max 8B):
 *   [0]   error_type (uint16_t)
 *   [1]   index   (int16_t)
 *   [2-5] float value (32bit)
 */
struct Module_issue : virtual public Base_message {
    uint16_t error_type = 0;
    int16_t  index      = 0;
    float    value      = 0.0f;

    Module_issue(uint16_t error_type = 0,
                 int16_t index = 0,
                 float value = 0.0f) :
        Base_message(Codes::Message_type::Module_issues),
        error_type(error_type),
        index(index),
        value(value)
    { }

    Module_issue(IssueType issue,
                 int16_t index,
                 float value = 0.0f) :
        Base_message(Codes::Message_type::Module_issues),
        error_type(static_cast<uint16_t>(issue)),
        index(index),
        value(value)
    { }

    virtual bool Interpret_data(can_data_vector_t &data) override final {
    if (data.size() != 8) {
        return false;
    }

    error_type = (data[0] << 8) | data[1];

    index = static_cast<int16_t>((data[2] << 8) | data[3]);

    can_data_vector_t float_bytes(data.begin() + 4, data.begin() + 8);
    App_messages::Float_message fm(0.0f, Codes::Message_type::Module_issues);
    fm.Interpret_data(float_bytes);
    value = fm.content;

    return true;
}

virtual can_data_vector_t Export_data() override final {
    can_data_vector_t data(8);

    data[0] = (error_type >> 8) & 0xff;
    data[1] = error_type & 0xff;

    data[2] = (index >> 8) & 0xff;
    data[3] = index & 0xff;

    App_messages::Float_message fm(value, Codes::Message_type::Module_issues);
    can_data_vector_t float_bytes = fm.Export_data();
    std::copy(float_bytes.begin(), float_bytes.end(), data.begin() + 4);

    return data;
}

};

};
