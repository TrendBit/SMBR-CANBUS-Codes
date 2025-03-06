/**
 * @file enums.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 06.03.2025
 */

#pragma once

#include <unordered_map>

namespace Fluorometer_config{
    /**
     * @brief   Number of bits of ADC converter
     */
    const uint adc_bits = 12;

    /**
     * @brief   Gain of detector
     */
    enum class Gain: uint8_t {
        Undefined = 0,
        x1 = 1,
        x10 = 2,
        x50 = 3,
        Auto = 4
    };

    const std::unordered_map<Gain, float> gain_values = {
        {Gain::x1, 1.0},
        {Gain::x10, 10.0},
        {Gain::x50, 50.0}
    };

    /**
     * @brief   Timing bases for sample collection
     *          Used to generate times at which samples are collected (sample spread in time)
     */
    enum class Timing{
        Undefined = 0,
        Linear = 1,
        Logarithmic = 2
    };

};
