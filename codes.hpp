/**
 * @file codes.hpp
 * @author Petr Malaník (TheColonelYoung(at)gmail(dot)com)
 * @version 0.1
 * @date 02.06.2024
 */

#pragma once

#define MAGIC_ENUM_RANGE_MIN 0
#define MAGIC_ENUM_RANGE_MAX 4096

#include <cstdint>
#include <string>

#include "tools/magic_enum.hpp"

/**
 * @brief   This namespace contains all enums with their respective value describing
 *              Modules, Instances, Messages and Components which are interacting over Network based on CAN Bus
 *          Intend of this header file is to be used as submodule in all repositories which needs to know this codes
 */
namespace Codes {
/**
 * @brief 8-bit identifier of device, together with 4 bit device enumeration creates, enumeration of device in system
 */
enum class Module : uint8_t {
    Undefined      = 0x00,
    All            = 0x01,
    Any            = 0x02,
    Test_module    = 0x03,
    Core_module    = 0x04, // Virtual RaspberryPi + Interface Board
    Control_module = 0x05,
    Sensor_module  = 0x06,
};

/**
 * @brief 4-bit identifier of instance of device, together with 8 bit device enumeration creates, enumeration of device in system
 *            Some modules can have multiple instances, some only one (this should be addressed with exclusive instance)
 */
enum class Instance : uint8_t {
    Undefined   = 0x00,
    Exclusive   = 0x01,
    All         = 0x02,
    Reserved    = 0x03,
    Instance_1  = 0x04,
    Instance_2  = 0x05,
    Instance_3  = 0x06,
    Instance_4  = 0x07,
    Instance_5  = 0x08,
    Instance_6  = 0x09,
    Instance_7  = 0x0a,
    Instance_8  = 0x0b,
    Instance_9  = 0x0c,
    Instance_10 = 0x0d,
    Instance_11 = 0x0e,
    Instance_12 = 0x0f,
};

/**
 * @brief  Identifier of abstract component of device
 *         Represent part of functionality of device
 */
enum class Component : uint32_t {
    Undefined          = 0x0000,
    Common_core        = 0x0001,
    CAN_serial         = 0x0002,
    LED_panel          = 0x0003,
    Cuvette_pump       = 0x0004,
    Bottle_aerator     = 0x0005,
    Bottle_mixer       = 0x0006,
    Bottle_heater      = 0x0007,
    Case_fan           = 0x0008,
    Mini_OLED          = 0x0009,
    Bottle_temperature = 0x000a,
};

/**
 * @brief  11-bit identifier used by Administration messages, which are not used for application level communication
 *              But for debugging, updating or development purposes.
 *         This codes are used in non extended frame format and every non extended frame is considered as administration message
 *         Numbers of Serial_port_RX/TX extend beyond range defined here
 */
enum class Command_admin : uint16_t {
    Undefined                = 0x000,
    Serial_probe             = 0x321,
    Serial_ID_respond        = 0x323,
    Serial_port_confirmation = 0x322,
    Serial_port_RX           = 0x180,
    Serial_port_TX           = 0x181,
};

/**
 * @brief   12-bit identifier from CAN message header (ID)
 *          This codes are used in extended frame format and every extended frame is considered as application message
 *          First 4 bytes are used for message type code and also determine priority
 */
enum class Message_type : uint16_t {
    // 0x0 - Module specific - Emergency
    Undefined = 0x000,

    // 0x1 - Module specific - High priority

    // 0x2 - Common messages - High priority
    Device_reset                                = 0x200,
    Device_usb_bootloader                       = 0x201,
    Device_can_bootloader                       = 0x202,

    Core_SID_request                            = 0x210,
    Core_SID_response                           = 0x211,
    Core_IP_request                             = 0x212,
    Core_IP_response                            = 0x213,
    Core_hostname_request                       = 0x214,
    Core_hostname_response                      = 0x215,
    Core_serial_request                         = 0x216,
    Core_serial_response                        = 0x217,

    // 0x3 - Shared messages - High priority
    Probe_modules_request                       = 0x300,
    Probe_modules_response                      = 0x301,

    // 0x4 - Module specific
    Supply_type_request                         = 0x400,
    Supply_type_response                        = 0x401,
    Supply_5V_rail_request                      = 0x402,
    Supply_5V_rail_response                     = 0x403,
    Supply_VIN_rail_request                     = 0x404,
    Supply_VIN_rail_response                    = 0x405,
    Supply_POE_rail_request                     = 0x406,
    Supply_POE_rail_response                    = 0x407,
    Supply_current_request                      = 0x408,
    Supply_current_response                     = 0x409,
    Supply_power_draw_request                   = 0x40a,
    Supply_power_draw_response                  = 0x40b,

    LED_set_intensity                           = 0x410,
    LED_get_intensity_request                   = 0x411,
    LED_get_intensity_response                  = 0x412,
    LED_get_temperature_request                 = 0x413,
    LED_get_temperature_response                = 0x414,

    Heater_set_intensity                        = 0x420,
    Heater_get_intensity_request                = 0x421,
    Heater_get_intensity_response               = 0x422,
    Heater_set_target_temperature               = 0x423,
    Heater_get_target_temperature_request       = 0x424,
    Heater_get_target_temperature_response      = 0x425,
    Heater_get_plate_temperature_request        = 0x426,
    Heater_get_plate_temperature_response       = 0x427,
    Heater_turn_off                             = 0x428,

    Cuvette_pump_set_speed                      = 0x430,
    Cuvette_pump_get_speed_request              = 0x431,
    Cuvette_pump_get_speed_response             = 0x432,
    Cuvette_pump_set_flowrate                   = 0x433,
    Cuvette_pump_get_flowrate_request           = 0x434,
    Cuvette_pump_get_flowrate_response          = 0x435,
    Cuvette_pump_move                           = 0x436,
    Cuvette_pump_stop                           = 0x437,
    Cuvette_pump_prime                          = 0x438,
    Cuvette_pump_purge                          = 0x439,

    Aerator_set_speed                           = 0x440,
    Aerator_get_speed_request                   = 0x441,
    Aerator_get_speed_response                  = 0x442,
    Aerator_set_flowrate                        = 0x443,
    Aerator_get_flowrate_request                = 0x444,
    Aerator_get_flowrate_response               = 0x445,
    Aerator_move                                = 0x446,
    Aerator_stop                                = 0x447,

    Mixer_set_speed                             = 0x450,
    Mixer_get_speed_request                     = 0x451,
    Mixer_get_speed_response                    = 0x452,
    Mixer_set_rpm                               = 0x453,
    Mixer_get_rpm_request                       = 0x454,
    Mixer_get_rpm_response                      = 0x455,
    Mixer_stir                                  = 0x456,
    Mixer_stop                                  = 0x457,

    Bottle_temperature_request                  = 0x460,
    Bottle_temperature_response                 = 0x461,
    Bottle_top_measured_temperature_request     = 0x462,
    Bottle_top_measured_temperature_response    = 0x463,
    Bottle_bottom_measured_temperature_request  = 0x464,
    Bottle_bottom_measured_temperature_response = 0x465,
    Bottle_top_sensor_temperature_request       = 0x466,
    Bottle_top_sensor_temperature_response      = 0x467,
    Bottle_bottom_sensor_temperature_request    = 0x468,
    Bottle_bottom_sensor_temperature_response   = 0x469,

    Mini_OLED_clear_custom_text                 = 0x470,
    Mini_OLED_print_custom_text                 = 0x471,

    // 0x5 - Module specific
    // 0x6 - Module specific
    // 0x7 - Module specific
    // 0x8 - Module specific
    // 0x9 - Reserved for future use
    // 0xa - Common messages
    Core_load_request          = 0xa00,
    Core_load_response         = 0xa01,
    Core_temperature_request   = 0xa02,
    Core_temperature_response  = 0xa03,
    Board_temperature_request  = 0xa04,
    Board_temperature_response = 0xa05,

    // 0xb - Common messages
    Ping_request               = 0xb00,
    Ping_response              = 0xb01,

    // 0xc - Shared messages
    // 0xd - Reserved for future use
    // 0xe - Error messages
    // 0xf - Debugging
};

    /**
     * @brief   Convert Module enum to string representation
     *
     * @param module        Module enum to convert
     * @return std::string  String representation of module
     */
    std::string to_string(Module module);

    /**
     * @brief   Convert Instance enum to string representation
     *
     * @param instance      Instance enum to convert
     * @return std::string  String representation of instance
     */
    std::string to_string(Instance instance);

    /**
     * @brief   Convert Component enum to string representation
     *
     * @param component     Component enum to convert
     * @return std::string  String representation of component
     */
    std::string to_string(Component component);

    /**
     * @brief   Convert Message_type enum to string representation
     *
     * @param command       Message_type enum to convert
     * @return std::string  String representation of message type
     */
    std::string to_string(Message_type command);
}
