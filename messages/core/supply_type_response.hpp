/**
 * @file supply_type_response.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 20.01.2025
 */

#pragma once

#include "codes/codes.hpp"

#include "base_message.hpp"

namespace App_messages::Core {
    /**
     * @brief   Response to supply type request, contains type of supply connected to device
     *              Members:
     *                      bool vin: Main barrel jack 12V power supply
     *                      bool poe: Power over Ethernet
     *                      bool poe_hb: PoE high budget at (25-35W), when true also sets poe to true
     */
    struct Supply_type_response : virtual public Base_message {
        bool vin = false;
        bool poe = false;
        bool poe_hb = false;

        Supply_type_response(bool vin = false, bool poe = false, bool poe_hb = false):
            Base_message(Codes::Message_type::Supply_type_response),
            vin(vin), poe(poe), poe_hb(poe_hb)
        {}

        virtual bool Interpret_data(can_data_vector_t &data) override final {
            if (data.size() != 1) {
                return false;
            }
            vin = data[0] & 0b00000001;
            poe = data[0] & 0b00000010;
            poe_hb = data[0] & 0b00000100;

            return true;
        }

        virtual can_data_vector_t Export_data() override final {
            can_data_vector_t data(1);
            data[0] = 0;

            if (vin) {
                data[0] |= 0b00000001;
            }

            if (poe) {
                data[0] |= 0b00000010;
            }

            if (poe_hb) {
                data[0] |= 0b00000100;
            }

            return data;
        }

    };

}
