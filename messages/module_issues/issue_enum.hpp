#pragma once
#include <cstdint>

namespace App_messages::Module_issue {

enum class IssueType : uint8_t {
    // ===== Common (0–29) =====
    HighLoad                = 0,
    CoreOverTemp            = 1,
    BoardOverTemp           = 2,
    LowEEPROMMemory         = 3,
 
    // ===== Core (30–59) =====
    Invalid5VSupply         = 30,
    InvalidVinSupply        = 31,
    InvalidPoESupply        = 32,
    OverCurrentDraw         = 33,
    OverPowerDraw           = 34,

    // ===== Control (60–99) =====
    LEDPanelOverTemp        = 60,
    HeaterOverTemp          = 61,
    PumpInvalidSpeed        = 62,
    PumpInvalidFlowrate     = 63,
    AeratorOverSpeed        = 64,
    AeratorInvalidFlowrate  = 65,
    MixerOverSpeed          = 66,
    MixerOverRPM            = 67,


    // ===== Sensor (100–139) =====
    BottleOverTemp                     = 100,
    BottleTopOverMeasTemp              = 101,
    BottleBottomOverMeasTemp           = 102,
    BottleTopOverSensorTemp            = 103,
    BottleBottomOverSensorTemp         = 104,
    FluorometerDetectorOverTemp        = 105,
    FluorometerEmitorOverTemp          = 106,
    SpectrophotometerEmitorOverTemp    = 107


};

enum class Severity : uint8_t {
    Info     = 0,  // 0–3
    Warning  = 4,  // 4–7
    Error    = 8,  // 8–11
    Critical = 12, // 12–15
};

}
