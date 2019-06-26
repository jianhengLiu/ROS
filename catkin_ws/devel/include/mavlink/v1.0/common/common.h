/** @file
 *  @brief MAVLink comm protocol generated from common.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_COMMON_H
#define MAVLINK_COMMON_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_COMMON.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 1

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {9, 31, 12, 0, 14, 28, 3, 32, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 20, 2, 25, 23, 30, 101, 22, 26, 16, 14, 28, 32, 28, 28, 22, 22, 21, 6, 6, 37, 4, 4, 2, 2, 4, 2, 2, 3, 13, 12, 37, 4, 0, 0, 27, 25, 0, 0, 0, 0, 0, 72, 26, 181, 225, 42, 6, 4, 0, 11, 18, 0, 0, 37, 20, 35, 33, 3, 0, 0, 0, 22, 39, 37, 53, 51, 53, 51, 0, 28, 56, 42, 33, 81, 0, 0, 0, 0, 0, 0, 26, 32, 32, 20, 32, 62, 44, 64, 84, 9, 254, 16, 12, 36, 44, 64, 22, 6, 14, 12, 97, 2, 2, 113, 35, 6, 79, 35, 35, 22, 13, 255, 14, 18, 43, 8, 22, 14, 36, 43, 41, 32, 243, 14, 93, 0, 100, 36, 60, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42, 40, 63, 182, 40, 42, 0, 0, 0, 0, 0, 32, 52, 53, 6, 2, 38, 19, 254, 36, 30, 18, 18, 51, 9, 0}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {50, 124, 137, 0, 237, 217, 104, 119, 0, 0, 0, 89, 0, 0, 0, 0, 0, 0, 0, 0, 214, 159, 220, 168, 24, 23, 170, 144, 67, 115, 39, 246, 185, 104, 237, 244, 222, 212, 9, 254, 230, 28, 28, 132, 221, 232, 11, 153, 41, 39, 78, 196, 0, 0, 15, 3, 0, 0, 0, 0, 0, 167, 183, 119, 191, 118, 148, 21, 0, 243, 124, 0, 0, 38, 20, 158, 152, 143, 0, 0, 0, 106, 49, 22, 143, 140, 5, 150, 0, 231, 183, 63, 54, 47, 0, 0, 0, 0, 0, 0, 175, 102, 158, 208, 56, 93, 138, 108, 32, 185, 84, 34, 174, 124, 237, 4, 76, 128, 56, 116, 134, 237, 203, 250, 87, 203, 220, 25, 226, 46, 29, 223, 85, 6, 229, 203, 1, 195, 109, 168, 181, 47, 72, 131, 127, 0, 103, 154, 178, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 163, 105, 151, 35, 150, 179, 0, 0, 0, 0, 0, 90, 104, 85, 95, 130, 184, 81, 8, 204, 49, 170, 44, 83, 46, 0}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_COMMON

// ENUM DEFINITIONS


/** @brief Micro air vehicle / autopilot classes. This identifies the individual model. */
#ifndef HAVE_ENUM_MAV_AUTOPILOT
#define HAVE_ENUM_MAV_AUTOPILOT
typedef enum MAV_AUTOPILOT
{
   MAV_AUTOPILOT_GENERIC=0, /* Generic autopilot, full support for everything | */
   MAV_AUTOPILOT_RESERVED=1, /* Reserved for future use. | */
   MAV_AUTOPILOT_SLUGS=2, /* SLUGS autopilot, http://slugsuav.soe.ucsc.edu | */
   MAV_AUTOPILOT_ARDUPILOTMEGA=3, /* ArduPilot - Plane/Copter/Rover/Sub/Tracker, http://ardupilot.org | */
   MAV_AUTOPILOT_OPENPILOT=4, /* OpenPilot, http://openpilot.org | */
   MAV_AUTOPILOT_GENERIC_WAYPOINTS_ONLY=5, /* Generic autopilot only supporting simple waypoints | */
   MAV_AUTOPILOT_GENERIC_WAYPOINTS_AND_SIMPLE_NAVIGATION_ONLY=6, /* Generic autopilot supporting waypoints and other simple navigation commands | */
   MAV_AUTOPILOT_GENERIC_MISSION_FULL=7, /* Generic autopilot supporting the full mission command set | */
   MAV_AUTOPILOT_INVALID=8, /* No valid autopilot, e.g. a GCS or other MAVLink component | */
   MAV_AUTOPILOT_PPZ=9, /* PPZ UAV - http://nongnu.org/paparazzi | */
   MAV_AUTOPILOT_UDB=10, /* UAV Dev Board | */
   MAV_AUTOPILOT_FP=11, /* FlexiPilot | */
   MAV_AUTOPILOT_PX4=12, /* PX4 Autopilot - http://px4.io/ | */
   MAV_AUTOPILOT_SMACCMPILOT=13, /* SMACCMPilot - http://smaccmpilot.org | */
   MAV_AUTOPILOT_AUTOQUAD=14, /* AutoQuad -- http://autoquad.org | */
   MAV_AUTOPILOT_ARMAZILA=15, /* Armazila -- http://armazila.com | */
   MAV_AUTOPILOT_AEROB=16, /* Aerob -- http://aerob.ru | */
   MAV_AUTOPILOT_ASLUAV=17, /* ASLUAV autopilot -- http://www.asl.ethz.ch | */
   MAV_AUTOPILOT_SMARTAP=18, /* SmartAP Autopilot - http://sky-drones.com | */
   MAV_AUTOPILOT_AIRRAILS=19, /* AirRails - http://uaventure.com | */
   MAV_AUTOPILOT_ENUM_END=20, /*  | */
} MAV_AUTOPILOT;
#endif

/** @brief  */
#ifndef HAVE_ENUM_MAV_TYPE
#define HAVE_ENUM_MAV_TYPE
typedef enum MAV_TYPE
{
   MAV_TYPE_GENERIC=0, /* Generic micro air vehicle. | */
   MAV_TYPE_FIXED_WING=1, /* Fixed wing aircraft. | */
   MAV_TYPE_QUADROTOR=2, /* Quadrotor | */
   MAV_TYPE_COAXIAL=3, /* Coaxial helicopter | */
   MAV_TYPE_HELICOPTER=4, /* Normal helicopter with tail rotor. | */
   MAV_TYPE_ANTENNA_TRACKER=5, /* Ground installation | */
   MAV_TYPE_GCS=6, /* Operator control unit / ground control station | */
   MAV_TYPE_AIRSHIP=7, /* Airship, controlled | */
   MAV_TYPE_FREE_BALLOON=8, /* Free balloon, uncontrolled | */
   MAV_TYPE_ROCKET=9, /* Rocket | */
   MAV_TYPE_GROUND_ROVER=10, /* Ground rover | */
   MAV_TYPE_SURFACE_BOAT=11, /* Surface vessel, boat, ship | */
   MAV_TYPE_SUBMARINE=12, /* Submarine | */
   MAV_TYPE_HEXAROTOR=13, /* Hexarotor | */
   MAV_TYPE_OCTOROTOR=14, /* Octorotor | */
   MAV_TYPE_TRICOPTER=15, /* Tricopter | */
   MAV_TYPE_FLAPPING_WING=16, /* Flapping wing | */
   MAV_TYPE_KITE=17, /* Kite | */
   MAV_TYPE_ONBOARD_CONTROLLER=18, /* Onboard companion controller | */
   MAV_TYPE_VTOL_DUOROTOR=19, /* Two-rotor VTOL using control surfaces in vertical operation in addition. Tailsitter. | */
   MAV_TYPE_VTOL_QUADROTOR=20, /* Quad-rotor VTOL using a V-shaped quad config in vertical operation. Tailsitter. | */
   MAV_TYPE_VTOL_TILTROTOR=21, /* Tiltrotor VTOL | */
   MAV_TYPE_VTOL_RESERVED2=22, /* VTOL reserved 2 | */
   MAV_TYPE_VTOL_RESERVED3=23, /* VTOL reserved 3 | */
   MAV_TYPE_VTOL_RESERVED4=24, /* VTOL reserved 4 | */
   MAV_TYPE_VTOL_RESERVED5=25, /* VTOL reserved 5 | */
   MAV_TYPE_GIMBAL=26, /* Onboard gimbal | */
   MAV_TYPE_ADSB=27, /* Onboard ADSB peripheral | */
   MAV_TYPE_PARAFOIL=28, /* Steerable, nonrigid airfoil | */
   MAV_TYPE_DODECAROTOR=29, /* Dodecarotor | */
   MAV_TYPE_CAMERA=30, /* Camera | */
   MAV_TYPE_CHARGING_STATION=31, /* Charging station | */
   MAV_TYPE_FLARM=32, /* Onboard FLARM collision avoidance system | */
   MAV_TYPE_ENUM_END=33, /*  | */
} MAV_TYPE;
#endif

/** @brief These values define the type of firmware release.  These values indicate the first version or release of this type.  For example the first alpha release would be 64, the second would be 65. */
#ifndef HAVE_ENUM_FIRMWARE_VERSION_TYPE
#define HAVE_ENUM_FIRMWARE_VERSION_TYPE
typedef enum FIRMWARE_VERSION_TYPE
{
   FIRMWARE_VERSION_TYPE_DEV=0, /* development release | */
   FIRMWARE_VERSION_TYPE_ALPHA=64, /* alpha release | */
   FIRMWARE_VERSION_TYPE_BETA=128, /* beta release | */
   FIRMWARE_VERSION_TYPE_RC=192, /* release candidate | */
   FIRMWARE_VERSION_TYPE_OFFICIAL=255, /* official stable release | */
   FIRMWARE_VERSION_TYPE_ENUM_END=256, /*  | */
} FIRMWARE_VERSION_TYPE;
#endif

/** @brief Flags to report failure cases over the high latency telemtry. */
#ifndef HAVE_ENUM_HL_FAILURE_FLAG
#define HAVE_ENUM_HL_FAILURE_FLAG
typedef enum HL_FAILURE_FLAG
{
   HL_FAILURE_FLAG_GPS=1, /* GPS failure. | */
   HL_FAILURE_FLAG_DIFFERENTIAL_PRESSURE=2, /* Differential pressure sensor failure. | */
   HL_FAILURE_FLAG_ABSOLUTE_PRESSURE=4, /* Absolute pressure sensor failure. | */
   HL_FAILURE_FLAG_3D_ACCEL=8, /* Accelerometer sensor failure. | */
   HL_FAILURE_FLAG_3D_GYRO=16, /* Gyroscope sensor failure. | */
   HL_FAILURE_FLAG_3D_MAG=32, /* Magnetometer sensor failure. | */
   HL_FAILURE_FLAG_TERRAIN=64, /* Terrain subsystem failure. | */
   HL_FAILURE_FLAG_BATTERY=128, /* Battery failure/critical low battery. | */
   HL_FAILURE_FLAG_RC_RECEIVER=256, /* RC receiver failure/no rc connection. | */
   HL_FAILURE_FLAG_OFFBOARD_LINK=512, /* Offboard link failure. | */
   HL_FAILURE_FLAG_ENGINE=1024, /* Engine failure. | */
   HL_FAILURE_FLAG_GEOFENCE=2048, /* Geofence violation. | */
   HL_FAILURE_FLAG_ESTIMATOR=4096, /* Estimator failure, for example measurement rejection or large variances. | */
   HL_FAILURE_FLAG_MISSION=8192, /* Mission failure. | */
   HL_FAILURE_FLAG_ENUM_END=8193, /*  | */
} HL_FAILURE_FLAG;
#endif

/** @brief These flags encode the MAV mode. */
#ifndef HAVE_ENUM_MAV_MODE_FLAG
#define HAVE_ENUM_MAV_MODE_FLAG
typedef enum MAV_MODE_FLAG
{
   MAV_MODE_FLAG_CUSTOM_MODE_ENABLED=1, /* 0b00000001 Reserved for future use. | */
   MAV_MODE_FLAG_TEST_ENABLED=2, /* 0b00000010 system has a test mode enabled. This flag is intended for temporary system tests and should not be used for stable implementations. | */
   MAV_MODE_FLAG_AUTO_ENABLED=4, /* 0b00000100 autonomous mode enabled, system finds its own goal positions. Guided flag can be set or not, depends on the actual implementation. | */
   MAV_MODE_FLAG_GUIDED_ENABLED=8, /* 0b00001000 guided mode enabled, system flies waypoints / mission items. | */
   MAV_MODE_FLAG_STABILIZE_ENABLED=16, /* 0b00010000 system stabilizes electronically its attitude (and optionally position). It needs however further control inputs to move around. | */
   MAV_MODE_FLAG_HIL_ENABLED=32, /* 0b00100000 hardware in the loop simulation. All motors / actuators are blocked, but internal software is full operational. | */
   MAV_MODE_FLAG_MANUAL_INPUT_ENABLED=64, /* 0b01000000 remote control input is enabled. | */
   MAV_MODE_FLAG_SAFETY_ARMED=128, /* 0b10000000 MAV safety set to armed. Motors are enabled / running / can start. Ready to fly. Additional note: this flag is to be ignore when sent in the command MAV_CMD_DO_SET_MODE and MAV_CMD_COMPONENT_ARM_DISARM shall be used instead. The flag can still be used to report the armed state. | */
   MAV_MODE_FLAG_ENUM_END=129, /*  | */
} MAV_MODE_FLAG;
#endif

/** @brief These values encode the bit positions of the decode position. These values can be used to read the value of a flag bit by combining the base_mode variable with AND with the flag position value. The result will be either 0 or 1, depending on if the flag is set or not. */
#ifndef HAVE_ENUM_MAV_MODE_FLAG_DECODE_POSITION
#define HAVE_ENUM_MAV_MODE_FLAG_DECODE_POSITION
typedef enum MAV_MODE_FLAG_DECODE_POSITION
{
   MAV_MODE_FLAG_DECODE_POSITION_CUSTOM_MODE=1, /* Eighth bit: 00000001 | */
   MAV_MODE_FLAG_DECODE_POSITION_TEST=2, /* Seventh bit: 00000010 | */
   MAV_MODE_FLAG_DECODE_POSITION_AUTO=4, /* Sixt bit:   00000100 | */
   MAV_MODE_FLAG_DECODE_POSITION_GUIDED=8, /* Fifth bit:  00001000 | */
   MAV_MODE_FLAG_DECODE_POSITION_STABILIZE=16, /* Fourth bit: 00010000 | */
   MAV_MODE_FLAG_DECODE_POSITION_HIL=32, /* Third bit:  00100000 | */
   MAV_MODE_FLAG_DECODE_POSITION_MANUAL=64, /* Second bit: 01000000 | */
   MAV_MODE_FLAG_DECODE_POSITION_SAFETY=128, /* First bit:  10000000 | */
   MAV_MODE_FLAG_DECODE_POSITION_ENUM_END=129, /*  | */
} MAV_MODE_FLAG_DECODE_POSITION;
#endif

/** @brief Override command, pauses current mission execution and moves immediately to a position */
#ifndef HAVE_ENUM_MAV_GOTO
#define HAVE_ENUM_MAV_GOTO
typedef enum MAV_GOTO
{
   MAV_GOTO_DO_HOLD=0, /* Hold at the current position. | */
   MAV_GOTO_DO_CONTINUE=1, /* Continue with the next item in mission execution. | */
   MAV_GOTO_HOLD_AT_CURRENT_POSITION=2, /* Hold at the current position of the system | */
   MAV_GOTO_HOLD_AT_SPECIFIED_POSITION=3, /* Hold at the position specified in the parameters of the DO_HOLD action | */
   MAV_GOTO_ENUM_END=4, /*  | */
} MAV_GOTO;
#endif

/** @brief These defines are predefined OR-combined mode flags. There is no need to use values from this enum, but it
               simplifies the use of the mode flags. Note that manual input is enabled in all modes as a safety override. */
#ifndef HAVE_ENUM_MAV_MODE
#define HAVE_ENUM_MAV_MODE
typedef enum MAV_MODE
{
   MAV_MODE_PREFLIGHT=0, /* System is not ready to fly, booting, calibrating, etc. No flag is set. | */
   MAV_MODE_MANUAL_DISARMED=64, /* System is allowed to be active, under manual (RC) control, no stabilization | */
   MAV_MODE_TEST_DISARMED=66, /* UNDEFINED mode. This solely depends on the autopilot - use with caution, intended for developers only. | */
   MAV_MODE_STABILIZE_DISARMED=80, /* System is allowed to be active, under assisted RC control. | */
   MAV_MODE_GUIDED_DISARMED=88, /* System is allowed to be active, under autonomous control, manual setpoint | */
   MAV_MODE_AUTO_DISARMED=92, /* System is allowed to be active, under autonomous control and navigation (the trajectory is decided onboard and not pre-programmed by waypoints) | */
   MAV_MODE_MANUAL_ARMED=192, /* System is allowed to be active, under manual (RC) control, no stabilization | */
   MAV_MODE_TEST_ARMED=194, /* UNDEFINED mode. This solely depends on the autopilot - use with caution, intended for developers only. | */
   MAV_MODE_STABILIZE_ARMED=208, /* System is allowed to be active, under assisted RC control. | */
   MAV_MODE_GUIDED_ARMED=216, /* System is allowed to be active, under autonomous control, manual setpoint | */
   MAV_MODE_AUTO_ARMED=220, /* System is allowed to be active, under autonomous control and navigation (the trajectory is decided onboard and not pre-programmed by waypoints) | */
   MAV_MODE_ENUM_END=221, /*  | */
} MAV_MODE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_MAV_STATE
#define HAVE_ENUM_MAV_STATE
typedef enum MAV_STATE
{
   MAV_STATE_UNINIT=0, /* Uninitialized system, state is unknown. | */
   MAV_STATE_BOOT=1, /* System is booting up. | */
   MAV_STATE_CALIBRATING=2, /* System is calibrating and not flight-ready. | */
   MAV_STATE_STANDBY=3, /* System is grounded and on standby. It can be launched any time. | */
   MAV_STATE_ACTIVE=4, /* System is active and might be already airborne. Motors are engaged. | */
   MAV_STATE_CRITICAL=5, /* System is in a non-normal flight mode. It can however still navigate. | */
   MAV_STATE_EMERGENCY=6, /* System is in a non-normal flight mode. It lost control over parts or over the whole airframe. It is in mayday and going down. | */
   MAV_STATE_POWEROFF=7, /* System just initialized its power-down sequence, will shut down now. | */
   MAV_STATE_FLIGHT_TERMINATION=8, /* System is terminating itself. | */
   MAV_STATE_ENUM_END=9, /*  | */
} MAV_STATE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_MAV_COMPONENT
#define HAVE_ENUM_MAV_COMPONENT
typedef enum MAV_COMPONENT
{
   MAV_COMP_ID_ALL=0, /*  | */
   MAV_COMP_ID_AUTOPILOT1=1, /*  | */
   MAV_COMP_ID_CAMERA=100, /*  | */
   MAV_COMP_ID_CAMERA2=101, /*  | */
   MAV_COMP_ID_CAMERA3=102, /*  | */
   MAV_COMP_ID_CAMERA4=103, /*  | */
   MAV_COMP_ID_CAMERA5=104, /*  | */
   MAV_COMP_ID_CAMERA6=105, /*  | */
   MAV_COMP_ID_SERVO1=140, /*  | */
   MAV_COMP_ID_SERVO2=141, /*  | */
   MAV_COMP_ID_SERVO3=142, /*  | */
   MAV_COMP_ID_SERVO4=143, /*  | */
   MAV_COMP_ID_SERVO5=144, /*  | */
   MAV_COMP_ID_SERVO6=145, /*  | */
   MAV_COMP_ID_SERVO7=146, /*  | */
   MAV_COMP_ID_SERVO8=147, /*  | */
   MAV_COMP_ID_SERVO9=148, /*  | */
   MAV_COMP_ID_SERVO10=149, /*  | */
   MAV_COMP_ID_SERVO11=150, /*  | */
   MAV_COMP_ID_SERVO12=151, /*  | */
   MAV_COMP_ID_SERVO13=152, /*  | */
   MAV_COMP_ID_SERVO14=153, /*  | */
   MAV_COMP_ID_GIMBAL=154, /*  | */
   MAV_COMP_ID_LOG=155, /*  | */
   MAV_COMP_ID_ADSB=156, /*  | */
   MAV_COMP_ID_OSD=157, /* On Screen Display (OSD) devices for video links | */
   MAV_COMP_ID_PERIPHERAL=158, /* Generic autopilot peripheral component ID. Meant for devices that do not implement the parameter sub-protocol | */
   MAV_COMP_ID_QX1_GIMBAL=159, /*  | */
   MAV_COMP_ID_FLARM=160, /*  | */
   MAV_COMP_ID_MAPPER=180, /*  | */
   MAV_COMP_ID_MISSIONPLANNER=190, /*  | */
   MAV_COMP_ID_PATHPLANNER=195, /*  | */
   MAV_COMP_ID_IMU=200, /*  | */
   MAV_COMP_ID_IMU_2=201, /*  | */
   MAV_COMP_ID_IMU_3=202, /*  | */
   MAV_COMP_ID_GPS=220, /*  | */
   MAV_COMP_ID_GPS2=221, /*  | */
   MAV_COMP_ID_UDP_BRIDGE=240, /*  | */
   MAV_COMP_ID_UART_BRIDGE=241, /*  | */
   MAV_COMP_ID_SYSTEM_CONTROL=250, /*  | */
   MAV_COMPONENT_ENUM_END=251, /*  | */
} MAV_COMPONENT;
#endif

/** @brief These encode the sensors whose status is sent as part of the SYS_STATUS message. */
#ifndef HAVE_ENUM_MAV_SYS_STATUS_SENSOR
#define HAVE_ENUM_MAV_SYS_STATUS_SENSOR
typedef enum MAV_SYS_STATUS_SENSOR
{
   MAV_SYS_STATUS_SENSOR_3D_GYRO=1, /* 0x01 3D gyro | */
   MAV_SYS_STATUS_SENSOR_3D_ACCEL=2, /* 0x02 3D accelerometer | */
   MAV_SYS_STATUS_SENSOR_3D_MAG=4, /* 0x04 3D magnetometer | */
   MAV_SYS_STATUS_SENSOR_ABSOLUTE_PRESSURE=8, /* 0x08 absolute pressure | */
   MAV_SYS_STATUS_SENSOR_DIFFERENTIAL_PRESSURE=16, /* 0x10 differential pressure | */
   MAV_SYS_STATUS_SENSOR_GPS=32, /* 0x20 GPS | */
   MAV_SYS_STATUS_SENSOR_OPTICAL_FLOW=64, /* 0x40 optical flow | */
   MAV_SYS_STATUS_SENSOR_VISION_POSITION=128, /* 0x80 computer vision position | */
   MAV_SYS_STATUS_SENSOR_LASER_POSITION=256, /* 0x100 laser based position | */
   MAV_SYS_STATUS_SENSOR_EXTERNAL_GROUND_TRUTH=512, /* 0x200 external ground truth (Vicon or Leica) | */
   MAV_SYS_STATUS_SENSOR_ANGULAR_RATE_CONTROL=1024, /* 0x400 3D angular rate control | */
   MAV_SYS_STATUS_SENSOR_ATTITUDE_STABILIZATION=2048, /* 0x800 attitude stabilization | */
   MAV_SYS_STATUS_SENSOR_YAW_POSITION=4096, /* 0x1000 yaw position | */
   MAV_SYS_STATUS_SENSOR_Z_ALTITUDE_CONTROL=8192, /* 0x2000 z/altitude control | */
   MAV_SYS_STATUS_SENSOR_XY_POSITION_CONTROL=16384, /* 0x4000 x/y position control | */
   MAV_SYS_STATUS_SENSOR_MOTOR_OUTPUTS=32768, /* 0x8000 motor outputs / control | */
   MAV_SYS_STATUS_SENSOR_RC_RECEIVER=65536, /* 0x10000 rc receiver | */
   MAV_SYS_STATUS_SENSOR_3D_GYRO2=131072, /* 0x20000 2nd 3D gyro | */
   MAV_SYS_STATUS_SENSOR_3D_ACCEL2=262144, /* 0x40000 2nd 3D accelerometer | */
   MAV_SYS_STATUS_SENSOR_3D_MAG2=524288, /* 0x80000 2nd 3D magnetometer | */
   MAV_SYS_STATUS_GEOFENCE=1048576, /* 0x100000 geofence | */
   MAV_SYS_STATUS_AHRS=2097152, /* 0x200000 AHRS subsystem health | */
   MAV_SYS_STATUS_TERRAIN=4194304, /* 0x400000 Terrain subsystem health | */
   MAV_SYS_STATUS_REVERSE_MOTOR=8388608, /* 0x800000 Motors are reversed | */
   MAV_SYS_STATUS_LOGGING=16777216, /* 0x1000000 Logging | */
   MAV_SYS_STATUS_SENSOR_BATTERY=33554432, /* 0x2000000 Battery | */
   MAV_SYS_STATUS_SENSOR_PROXIMITY=67108864, /* 0x4000000 Proximity | */
   MAV_SYS_STATUS_SENSOR_SATCOM=134217728, /* 0x8000000 Satellite Communication  | */
   MAV_SYS_STATUS_SENSOR_ENUM_END=134217729, /*  | */
} MAV_SYS_STATUS_SENSOR;
#endif

/** @brief  */
#ifndef HAVE_ENUM_MAV_FRAME
#define HAVE_ENUM_MAV_FRAME
typedef enum MAV_FRAME
{
   MAV_FRAME_GLOBAL=0, /* Global coordinate frame, WGS84 coordinate system. First value / x: latitude, second value / y: longitude, third value / z: positive altitude over mean sea level (MSL). | */
   MAV_FRAME_LOCAL_NED=1, /* Local coordinate frame, Z-down (x: north, y: east, z: down). | */
   MAV_FRAME_MISSION=2, /* NOT a coordinate frame, indicates a mission command. | */
   MAV_FRAME_GLOBAL_RELATIVE_ALT=3, /* Global coordinate frame, WGS84 coordinate system, relative altitude over ground with respect to the home position. First value / x: latitude, second value / y: longitude, third value / z: positive altitude with 0 being at the altitude of the home location. | */
   MAV_FRAME_LOCAL_ENU=4, /* Local coordinate frame, Z-up (x: east, y: north, z: up). | */
   MAV_FRAME_GLOBAL_INT=5, /* Global coordinate frame, WGS84 coordinate system. First value / x: latitude in degrees*1.0e-7, second value / y: longitude in degrees*1.0e-7, third value / z: positive altitude over mean sea level (MSL). | */
   MAV_FRAME_GLOBAL_RELATIVE_ALT_INT=6, /* Global coordinate frame, WGS84 coordinate system, relative altitude over ground with respect to the home position. First value / x: latitude in degrees*10e-7, second value / y: longitude in degrees*10e-7, third value / z: positive altitude with 0 being at the altitude of the home location. | */
   MAV_FRAME_LOCAL_OFFSET_NED=7, /* Offset to the current local frame. Anything expressed in this frame should be added to the current local frame position. | */
   MAV_FRAME_BODY_NED=8, /* Setpoint in body NED frame. This makes sense if all position control is externalized - e.g. useful to command 2 m/s^2 acceleration to the right. | */
   MAV_FRAME_BODY_OFFSET_NED=9, /* Offset in body NED frame. This makes sense if adding setpoints to the current flight path, to avoid an obstacle - e.g. useful to command 2 m/s^2 acceleration to the east. | */
   MAV_FRAME_GLOBAL_TERRAIN_ALT=10, /* Global (WGS84) coordinate frame with AGL altitude (at the waypoint coordinate). First value / x: latitude in degrees, second value / y: longitude in degrees, third value / z: positive altitude in meters with 0 being at ground level in terrain model. | */
   MAV_FRAME_GLOBAL_TERRAIN_ALT_INT=11, /* Global (WGS84) coordinate frame with AGL altitude (at the waypoint coordinate). First value / x: latitude in degrees*10e-7, second value / y: longitude in degrees*10e-7, third value / z: positive altitude in meters with 0 being at ground level in terrain model. | */
   MAV_FRAME_BODY_FRD=12, /* Body fixed frame of reference, Z-down (x: forward, y: right, z: down). | */
   MAV_FRAME_BODY_FLU=13, /* Body fixed frame of reference, Z-up (x: forward, y: left, z: up). | */
   MAV_FRAME_MOCAP_NED=14, /* Odometry local coordinate frame of data given by a motion capture system, Z-down (x: north, y: east, z: down). | */
   MAV_FRAME_MOCAP_ENU=15, /* Odometry local coordinate frame of data given by a motion capture system, Z-up (x: east, y: north, z: up). | */
   MAV_FRAME_VISION_NED=16, /* Odometry local coordinate frame of data given by a vision estimation system, Z-down (x: north, y: east, z: down). | */
   MAV_FRAME_VISION_ENU=17, /* Odometry local coordinate frame of data given by a vision estimation system, Z-up (x: east, y: north, z: up). | */
   MAV_FRAME_ESTIM_NED=18, /* Odometry local coordinate frame of data given by an estimator running onboard the vehicle, Z-down (x: north, y: east, z: down). | */
   MAV_FRAME_ESTIM_ENU=19, /* Odometry local coordinate frame of data given by an estimator running onboard the vehicle, Z-up (x: east, y: noth, z: up). | */
   MAV_FRAME_ENUM_END=20, /*  | */
} MAV_FRAME;
#endif

/** @brief  */
#ifndef HAVE_ENUM_MAVLINK_DATA_STREAM_TYPE
#define HAVE_ENUM_MAVLINK_DATA_STREAM_TYPE
typedef enum MAVLINK_DATA_STREAM_TYPE
{
   MAVLINK_DATA_STREAM_IMG_JPEG=1, /*  | */
   MAVLINK_DATA_STREAM_IMG_BMP=2, /*  | */
   MAVLINK_DATA_STREAM_IMG_RAW8U=3, /*  | */
   MAVLINK_DATA_STREAM_IMG_RAW32U=4, /*  | */
   MAVLINK_DATA_STREAM_IMG_PGM=5, /*  | */
   MAVLINK_DATA_STREAM_IMG_PNG=6, /*  | */
   MAVLINK_DATA_STREAM_TYPE_ENUM_END=7, /*  | */
} MAVLINK_DATA_STREAM_TYPE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_FENCE_ACTION
#define HAVE_ENUM_FENCE_ACTION
typedef enum FENCE_ACTION
{
   FENCE_ACTION_NONE=0, /* Disable fenced mode | */
   FENCE_ACTION_GUIDED=1, /* Switched to guided mode to return point (fence point 0) | */
   FENCE_ACTION_REPORT=2, /* Report fence breach, but don't take action | */
   FENCE_ACTION_GUIDED_THR_PASS=3, /* Switched to guided mode to return point (fence point 0) with manual throttle control | */
   FENCE_ACTION_RTL=4, /* Switch to RTL (return to launch) mode and head for the return point. | */
   FENCE_ACTION_ENUM_END=5, /*  | */
} FENCE_ACTION;
#endif

/** @brief  */
#ifndef HAVE_ENUM_FENCE_BREACH
#define HAVE_ENUM_FENCE_BREACH
typedef enum FENCE_BREACH
{
   FENCE_BREACH_NONE=0, /* No last fence breach | */
   FENCE_BREACH_MINALT=1, /* Breached minimum altitude | */
   FENCE_BREACH_MAXALT=2, /* Breached maximum altitude | */
   FENCE_BREACH_BOUNDARY=3, /* Breached fence boundary | */
   FENCE_BREACH_ENUM_END=4, /*  | */
} FENCE_BREACH;
#endif

/** @brief Enumeration of possible mount operation modes */
#ifndef HAVE_ENUM_MAV_MOUNT_MODE
#define HAVE_ENUM_MAV_MOUNT_MODE
typedef enum MAV_MOUNT_MODE
{
   MAV_MOUNT_MODE_RETRACT=0, /* Load and keep safe position (Roll,Pitch,Yaw) from permant memory and stop stabilization | */
   MAV_MOUNT_MODE_NEUTRAL=1, /* Load and keep neutral position (Roll,Pitch,Yaw) from permanent memory. | */
   MAV_MOUNT_MODE_MAVLINK_TARGETING=2, /* Load neutral position and start MAVLink Roll,Pitch,Yaw control with stabilization | */
   MAV_MOUNT_MODE_RC_TARGETING=3, /* Load neutral position and start RC Roll,Pitch,Yaw control with stabilization | */
   MAV_MOUNT_MODE_GPS_POINT=4, /* Load neutral position and start to point to Lat,Lon,Alt | */
   MAV_MOUNT_MODE_ENUM_END=5, /*  | */
} MAV_MOUNT_MODE;
#endif

/** @brief Generalized UAVCAN node health */
#ifndef HAVE_ENUM_UAVCAN_NODE_HEALTH
#define HAVE_ENUM_UAVCAN_NODE_HEALTH
typedef enum UAVCAN_NODE_HEALTH
{
   UAVCAN_NODE_HEALTH_OK=0, /* The node is functioning properly. | */
   UAVCAN_NODE_HEALTH_WARNING=1, /* A critical parameter went out of range or the node has encountered a minor failure. | */
   UAVCAN_NODE_HEALTH_ERROR=2, /* The node has encountered a major failure. | */
   UAVCAN_NODE_HEALTH_CRITICAL=3, /* The node has suffered a fatal malfunction. | */
   UAVCAN_NODE_HEALTH_ENUM_END=4, /*  | */
} UAVCAN_NODE_HEALTH;
#endif

/** @brief Generalized UAVCAN node mode */
#ifndef HAVE_ENUM_UAVCAN_NODE_MODE
#define HAVE_ENUM_UAVCAN_NODE_MODE
typedef enum UAVCAN_NODE_MODE
{
   UAVCAN_NODE_MODE_OPERATIONAL=0, /* The node is performing its primary functions. | */
   UAVCAN_NODE_MODE_INITIALIZATION=1, /* The node is initializing; this mode is entered immediately after startup. | */
   UAVCAN_NODE_MODE_MAINTENANCE=2, /* The node is under maintenance. | */
   UAVCAN_NODE_MODE_SOFTWARE_UPDATE=3, /* The node is in the process of updating its software. | */
   UAVCAN_NODE_MODE_OFFLINE=7, /* The node is no longer available online. | */
   UAVCAN_NODE_MODE_ENUM_END=8, /*  | */
} UAVCAN_NODE_MODE;
#endif

/** @brief A data stream is not a fixed set of messages, but rather a
     recommendation to the autopilot software. Individual autopilots may or may not obey
     the recommended messages. */
#ifndef HAVE_ENUM_MAV_DATA_STREAM
#define HAVE_ENUM_MAV_DATA_STREAM
typedef enum MAV_DATA_STREAM
{
   MAV_DATA_STREAM_ALL=0, /* Enable all data streams | */
   MAV_DATA_STREAM_RAW_SENSORS=1, /* Enable IMU_RAW, GPS_RAW, GPS_STATUS packets. | */
   MAV_DATA_STREAM_EXTENDED_STATUS=2, /* Enable GPS_STATUS, CONTROL_STATUS, AUX_STATUS | */
   MAV_DATA_STREAM_RC_CHANNELS=3, /* Enable RC_CHANNELS_SCALED, RC_CHANNELS_RAW, SERVO_OUTPUT_RAW | */
   MAV_DATA_STREAM_RAW_CONTROLLER=4, /* Enable ATTITUDE_CONTROLLER_OUTPUT, POSITION_CONTROLLER_OUTPUT, NAV_CONTROLLER_OUTPUT. | */
   MAV_DATA_STREAM_POSITION=6, /* Enable LOCAL_POSITION, GLOBAL_POSITION/GLOBAL_POSITION_INT messages. | */
   MAV_DATA_STREAM_EXTRA1=10, /* Dependent on the autopilot | */
   MAV_DATA_STREAM_EXTRA2=11, /* Dependent on the autopilot | */
   MAV_DATA_STREAM_EXTRA3=12, /* Dependent on the autopilot | */
   MAV_DATA_STREAM_ENUM_END=13, /*  | */
} MAV_DATA_STREAM;
#endif

/** @brief The ROI (region of interest) for the vehicle. This can be
                be used by the vehicle for camera/vehicle attitude alignment (see
                MAV_CMD_NAV_ROI). */
#ifndef HAVE_ENUM_MAV_ROI
#define HAVE_ENUM_MAV_ROI
typedef enum MAV_ROI
{
   MAV_ROI_NONE=0, /* No region of interest. | */
   MAV_ROI_WPNEXT=1, /* Point toward next waypoint, with optional pitch/roll/yaw offset. | */
   MAV_ROI_WPINDEX=2, /* Point toward given waypoint. | */
   MAV_ROI_LOCATION=3, /* Point toward fixed location. | */
   MAV_ROI_TARGET=4, /* Point toward of given id. | */
   MAV_ROI_ENUM_END=5, /*  | */
} MAV_ROI;
#endif

/** @brief ACK / NACK / ERROR values as a result of MAV_CMDs and for mission item transmission. */
#ifndef HAVE_ENUM_MAV_CMD_ACK
#define HAVE_ENUM_MAV_CMD_ACK
typedef enum MAV_CMD_ACK
{
   MAV_CMD_ACK_OK=1, /* Command / mission item is ok. | */
   MAV_CMD_ACK_ERR_FAIL=2, /* Generic error message if none of the other reasons fails or if no detailed error reporting is implemented. | */
   MAV_CMD_ACK_ERR_ACCESS_DENIED=3, /* The system is refusing to accept this command from this source / communication partner. | */
   MAV_CMD_ACK_ERR_NOT_SUPPORTED=4, /* Command or mission item is not supported, other commands would be accepted. | */
   MAV_CMD_ACK_ERR_COORDINATE_FRAME_NOT_SUPPORTED=5, /* The coordinate frame of this command / mission item is not supported. | */
   MAV_CMD_ACK_ERR_COORDINATES_OUT_OF_RANGE=6, /* The coordinate frame of this command is ok, but he coordinate values exceed the safety limits of this system. This is a generic error, please use the more specific error messages below if possible. | */
   MAV_CMD_ACK_ERR_X_LAT_OUT_OF_RANGE=7, /* The X or latitude value is out of range. | */
   MAV_CMD_ACK_ERR_Y_LON_OUT_OF_RANGE=8, /* The Y or longitude value is out of range. | */
   MAV_CMD_ACK_ERR_Z_ALT_OUT_OF_RANGE=9, /* The Z or altitude value is out of range. | */
   MAV_CMD_ACK_ENUM_END=10, /*  | */
} MAV_CMD_ACK;
#endif

/** @brief Specifies the datatype of a MAVLink parameter. */
#ifndef HAVE_ENUM_MAV_PARAM_TYPE
#define HAVE_ENUM_MAV_PARAM_TYPE
typedef enum MAV_PARAM_TYPE
{
   MAV_PARAM_TYPE_UINT8=1, /* 8-bit unsigned integer | */
   MAV_PARAM_TYPE_INT8=2, /* 8-bit signed integer | */
   MAV_PARAM_TYPE_UINT16=3, /* 16-bit unsigned integer | */
   MAV_PARAM_TYPE_INT16=4, /* 16-bit signed integer | */
   MAV_PARAM_TYPE_UINT32=5, /* 32-bit unsigned integer | */
   MAV_PARAM_TYPE_INT32=6, /* 32-bit signed integer | */
   MAV_PARAM_TYPE_UINT64=7, /* 64-bit unsigned integer | */
   MAV_PARAM_TYPE_INT64=8, /* 64-bit signed integer | */
   MAV_PARAM_TYPE_REAL32=9, /* 32-bit floating-point | */
   MAV_PARAM_TYPE_REAL64=10, /* 64-bit floating-point | */
   MAV_PARAM_TYPE_ENUM_END=11, /*  | */
} MAV_PARAM_TYPE;
#endif

/** @brief Specifies the datatype of a MAVLink extended parameter. */
#ifndef HAVE_ENUM_MAV_PARAM_EXT_TYPE
#define HAVE_ENUM_MAV_PARAM_EXT_TYPE
typedef enum MAV_PARAM_EXT_TYPE
{
   MAV_PARAM_EXT_TYPE_UINT8=1, /* 8-bit unsigned integer | */
   MAV_PARAM_EXT_TYPE_INT8=2, /* 8-bit signed integer | */
   MAV_PARAM_EXT_TYPE_UINT16=3, /* 16-bit unsigned integer | */
   MAV_PARAM_EXT_TYPE_INT16=4, /* 16-bit signed integer | */
   MAV_PARAM_EXT_TYPE_UINT32=5, /* 32-bit unsigned integer | */
   MAV_PARAM_EXT_TYPE_INT32=6, /* 32-bit signed integer | */
   MAV_PARAM_EXT_TYPE_UINT64=7, /* 64-bit unsigned integer | */
   MAV_PARAM_EXT_TYPE_INT64=8, /* 64-bit signed integer | */
   MAV_PARAM_EXT_TYPE_REAL32=9, /* 32-bit floating-point | */
   MAV_PARAM_EXT_TYPE_REAL64=10, /* 64-bit floating-point | */
   MAV_PARAM_EXT_TYPE_CUSTOM=11, /* Custom Type | */
   MAV_PARAM_EXT_TYPE_ENUM_END=12, /*  | */
} MAV_PARAM_EXT_TYPE;
#endif

/** @brief result from a mavlink command */
#ifndef HAVE_ENUM_MAV_RESULT
#define HAVE_ENUM_MAV_RESULT
typedef enum MAV_RESULT
{
   MAV_RESULT_ACCEPTED=0, /* Command ACCEPTED and EXECUTED | */
   MAV_RESULT_TEMPORARILY_REJECTED=1, /* Command TEMPORARY REJECTED/DENIED | */
   MAV_RESULT_DENIED=2, /* Command PERMANENTLY DENIED | */
   MAV_RESULT_UNSUPPORTED=3, /* Command UNKNOWN/UNSUPPORTED | */
   MAV_RESULT_FAILED=4, /* Command executed, but failed | */
   MAV_RESULT_IN_PROGRESS=5, /* WIP: Command being executed | */
   MAV_RESULT_ENUM_END=6, /*  | */
} MAV_RESULT;
#endif

/** @brief result in a MAVLink mission ack */
#ifndef HAVE_ENUM_MAV_MISSION_RESULT
#define HAVE_ENUM_MAV_MISSION_RESULT
typedef enum MAV_MISSION_RESULT
{
   MAV_MISSION_ACCEPTED=0, /* mission accepted OK | */
   MAV_MISSION_ERROR=1, /* generic error / not accepting mission commands at all right now | */
   MAV_MISSION_UNSUPPORTED_FRAME=2, /* coordinate frame is not supported | */
   MAV_MISSION_UNSUPPORTED=3, /* command is not supported | */
   MAV_MISSION_NO_SPACE=4, /* mission item exceeds storage space | */
   MAV_MISSION_INVALID=5, /* one of the parameters has an invalid value | */
   MAV_MISSION_INVALID_PARAM1=6, /* param1 has an invalid value | */
   MAV_MISSION_INVALID_PARAM2=7, /* param2 has an invalid value | */
   MAV_MISSION_INVALID_PARAM3=8, /* param3 has an invalid value | */
   MAV_MISSION_INVALID_PARAM4=9, /* param4 has an invalid value | */
   MAV_MISSION_INVALID_PARAM5_X=10, /* x/param5 has an invalid value | */
   MAV_MISSION_INVALID_PARAM6_Y=11, /* y/param6 has an invalid value | */
   MAV_MISSION_INVALID_PARAM7=12, /* param7 has an invalid value | */
   MAV_MISSION_INVALID_SEQUENCE=13, /* received waypoint out of sequence | */
   MAV_MISSION_DENIED=14, /* not accepting any mission commands from this communication partner | */
   MAV_MISSION_RESULT_ENUM_END=15, /*  | */
} MAV_MISSION_RESULT;
#endif

/** @brief Indicates the severity level, generally used for status messages to indicate their relative urgency. Based on RFC-5424 using expanded definitions at: http://www.kiwisyslog.com/kb/info:-syslog-message-levels/. */
#ifndef HAVE_ENUM_MAV_SEVERITY
#define HAVE_ENUM_MAV_SEVERITY
typedef enum MAV_SEVERITY
{
   MAV_SEVERITY_EMERGENCY=0, /* System is unusable. This is a "panic" condition. | */
   MAV_SEVERITY_ALERT=1, /* Action should be taken immediately. Indicates error in non-critical systems. | */
   MAV_SEVERITY_CRITICAL=2, /* Action must be taken immediately. Indicates failure in a primary system. | */
   MAV_SEVERITY_ERROR=3, /* Indicates an error in secondary/redundant systems. | */
   MAV_SEVERITY_WARNING=4, /* Indicates about a possible future error if this is not resolved within a given timeframe. Example would be a low battery warning. | */
   MAV_SEVERITY_NOTICE=5, /* An unusual event has occurred, though not an error condition. This should be investigated for the root cause. | */
   MAV_SEVERITY_INFO=6, /* Normal operational messages. Useful for logging. No action is required for these messages. | */
   MAV_SEVERITY_DEBUG=7, /* Useful non-operational messages that can assist in debugging. These should not occur during normal operation. | */
   MAV_SEVERITY_ENUM_END=8, /*  | */
} MAV_SEVERITY;
#endif

/** @brief Power supply status flags (bitmask) */
#ifndef HAVE_ENUM_MAV_POWER_STATUS
#define HAVE_ENUM_MAV_POWER_STATUS
typedef enum MAV_POWER_STATUS
{
   MAV_POWER_STATUS_BRICK_VALID=1, /* main brick power supply valid | */
   MAV_POWER_STATUS_SERVO_VALID=2, /* main servo power supply valid for FMU | */
   MAV_POWER_STATUS_USB_CONNECTED=4, /* USB power is connected | */
   MAV_POWER_STATUS_PERIPH_OVERCURRENT=8, /* peripheral supply is in over-current state | */
   MAV_POWER_STATUS_PERIPH_HIPOWER_OVERCURRENT=16, /* hi-power peripheral supply is in over-current state | */
   MAV_POWER_STATUS_CHANGED=32, /* Power status has changed since boot | */
   MAV_POWER_STATUS_ENUM_END=33, /*  | */
} MAV_POWER_STATUS;
#endif

/** @brief SERIAL_CONTROL device types */
#ifndef HAVE_ENUM_SERIAL_CONTROL_DEV
#define HAVE_ENUM_SERIAL_CONTROL_DEV
typedef enum SERIAL_CONTROL_DEV
{
   SERIAL_CONTROL_DEV_TELEM1=0, /* First telemetry port | */
   SERIAL_CONTROL_DEV_TELEM2=1, /* Second telemetry port | */
   SERIAL_CONTROL_DEV_GPS1=2, /* First GPS port | */
   SERIAL_CONTROL_DEV_GPS2=3, /* Second GPS port | */
   SERIAL_CONTROL_DEV_SHELL=10, /* system shell | */
   SERIAL_CONTROL_DEV_ENUM_END=11, /*  | */
} SERIAL_CONTROL_DEV;
#endif

/** @brief SERIAL_CONTROL flags (bitmask) */
#ifndef HAVE_ENUM_SERIAL_CONTROL_FLAG
#define HAVE_ENUM_SERIAL_CONTROL_FLAG
typedef enum SERIAL_CONTROL_FLAG
{
   SERIAL_CONTROL_FLAG_REPLY=1, /* Set if this is a reply | */
   SERIAL_CONTROL_FLAG_RESPOND=2, /* Set if the sender wants the receiver to send a response as another SERIAL_CONTROL message | */
   SERIAL_CONTROL_FLAG_EXCLUSIVE=4, /* Set if access to the serial port should be removed from whatever driver is currently using it, giving exclusive access to the SERIAL_CONTROL protocol. The port can be handed back by sending a request without this flag set | */
   SERIAL_CONTROL_FLAG_BLOCKING=8, /* Block on writes to the serial port | */
   SERIAL_CONTROL_FLAG_MULTI=16, /* Send multiple replies until port is drained | */
   SERIAL_CONTROL_FLAG_ENUM_END=17, /*  | */
} SERIAL_CONTROL_FLAG;
#endif

/** @brief Enumeration of distance sensor types */
#ifndef HAVE_ENUM_MAV_DISTANCE_SENSOR
#define HAVE_ENUM_MAV_DISTANCE_SENSOR
typedef enum MAV_DISTANCE_SENSOR
{
   MAV_DISTANCE_SENSOR_LASER=0, /* Laser rangefinder, e.g. LightWare SF02/F or PulsedLight units | */
   MAV_DISTANCE_SENSOR_ULTRASOUND=1, /* Ultrasound rangefinder, e.g. MaxBotix units | */
   MAV_DISTANCE_SENSOR_INFRARED=2, /* Infrared rangefinder, e.g. Sharp units | */
   MAV_DISTANCE_SENSOR_RADAR=3, /* Radar type, e.g. uLanding units | */
   MAV_DISTANCE_SENSOR_UNKNOWN=4, /* Broken or unknown type, e.g. analog units | */
   MAV_DISTANCE_SENSOR_ENUM_END=5, /*  | */
} MAV_DISTANCE_SENSOR;
#endif

/** @brief Enumeration of sensor orientation, according to its rotations */
#ifndef HAVE_ENUM_MAV_SENSOR_ORIENTATION
#define HAVE_ENUM_MAV_SENSOR_ORIENTATION
typedef enum MAV_SENSOR_ORIENTATION
{
   MAV_SENSOR_ROTATION_NONE=0, /* Roll: 0, Pitch: 0, Yaw: 0 | */
   MAV_SENSOR_ROTATION_YAW_45=1, /* Roll: 0, Pitch: 0, Yaw: 45 | */
   MAV_SENSOR_ROTATION_YAW_90=2, /* Roll: 0, Pitch: 0, Yaw: 90 | */
   MAV_SENSOR_ROTATION_YAW_135=3, /* Roll: 0, Pitch: 0, Yaw: 135 | */
   MAV_SENSOR_ROTATION_YAW_180=4, /* Roll: 0, Pitch: 0, Yaw: 180 | */
   MAV_SENSOR_ROTATION_YAW_225=5, /* Roll: 0, Pitch: 0, Yaw: 225 | */
   MAV_SENSOR_ROTATION_YAW_270=6, /* Roll: 0, Pitch: 0, Yaw: 270 | */
   MAV_SENSOR_ROTATION_YAW_315=7, /* Roll: 0, Pitch: 0, Yaw: 315 | */
   MAV_SENSOR_ROTATION_ROLL_180=8, /* Roll: 180, Pitch: 0, Yaw: 0 | */
   MAV_SENSOR_ROTATION_ROLL_180_YAW_45=9, /* Roll: 180, Pitch: 0, Yaw: 45 | */
   MAV_SENSOR_ROTATION_ROLL_180_YAW_90=10, /* Roll: 180, Pitch: 0, Yaw: 90 | */
   MAV_SENSOR_ROTATION_ROLL_180_YAW_135=11, /* Roll: 180, Pitch: 0, Yaw: 135 | */
   MAV_SENSOR_ROTATION_PITCH_180=12, /* Roll: 0, Pitch: 180, Yaw: 0 | */
   MAV_SENSOR_ROTATION_ROLL_180_YAW_225=13, /* Roll: 180, Pitch: 0, Yaw: 225 | */
   MAV_SENSOR_ROTATION_ROLL_180_YAW_270=14, /* Roll: 180, Pitch: 0, Yaw: 270 | */
   MAV_SENSOR_ROTATION_ROLL_180_YAW_315=15, /* Roll: 180, Pitch: 0, Yaw: 315 | */
   MAV_SENSOR_ROTATION_ROLL_90=16, /* Roll: 90, Pitch: 0, Yaw: 0 | */
   MAV_SENSOR_ROTATION_ROLL_90_YAW_45=17, /* Roll: 90, Pitch: 0, Yaw: 45 | */
   MAV_SENSOR_ROTATION_ROLL_90_YAW_90=18, /* Roll: 90, Pitch: 0, Yaw: 90 | */
   MAV_SENSOR_ROTATION_ROLL_90_YAW_135=19, /* Roll: 90, Pitch: 0, Yaw: 135 | */
   MAV_SENSOR_ROTATION_ROLL_270=20, /* Roll: 270, Pitch: 0, Yaw: 0 | */
   MAV_SENSOR_ROTATION_ROLL_270_YAW_45=21, /* Roll: 270, Pitch: 0, Yaw: 45 | */
   MAV_SENSOR_ROTATION_ROLL_270_YAW_90=22, /* Roll: 270, Pitch: 0, Yaw: 90 | */
   MAV_SENSOR_ROTATION_ROLL_270_YAW_135=23, /* Roll: 270, Pitch: 0, Yaw: 135 | */
   MAV_SENSOR_ROTATION_PITCH_90=24, /* Roll: 0, Pitch: 90, Yaw: 0 | */
   MAV_SENSOR_ROTATION_PITCH_270=25, /* Roll: 0, Pitch: 270, Yaw: 0 | */
   MAV_SENSOR_ROTATION_PITCH_180_YAW_90=26, /* Roll: 0, Pitch: 180, Yaw: 90 | */
   MAV_SENSOR_ROTATION_PITCH_180_YAW_270=27, /* Roll: 0, Pitch: 180, Yaw: 270 | */
   MAV_SENSOR_ROTATION_ROLL_90_PITCH_90=28, /* Roll: 90, Pitch: 90, Yaw: 0 | */
   MAV_SENSOR_ROTATION_ROLL_180_PITCH_90=29, /* Roll: 180, Pitch: 90, Yaw: 0 | */
   MAV_SENSOR_ROTATION_ROLL_270_PITCH_90=30, /* Roll: 270, Pitch: 90, Yaw: 0 | */
   MAV_SENSOR_ROTATION_ROLL_90_PITCH_180=31, /* Roll: 90, Pitch: 180, Yaw: 0 | */
   MAV_SENSOR_ROTATION_ROLL_270_PITCH_180=32, /* Roll: 270, Pitch: 180, Yaw: 0 | */
   MAV_SENSOR_ROTATION_ROLL_90_PITCH_270=33, /* Roll: 90, Pitch: 270, Yaw: 0 | */
   MAV_SENSOR_ROTATION_ROLL_180_PITCH_270=34, /* Roll: 180, Pitch: 270, Yaw: 0 | */
   MAV_SENSOR_ROTATION_ROLL_270_PITCH_270=35, /* Roll: 270, Pitch: 270, Yaw: 0 | */
   MAV_SENSOR_ROTATION_ROLL_90_PITCH_180_YAW_90=36, /* Roll: 90, Pitch: 180, Yaw: 90 | */
   MAV_SENSOR_ROTATION_ROLL_90_YAW_270=37, /* Roll: 90, Pitch: 0, Yaw: 270 | */
   MAV_SENSOR_ROTATION_ROLL_90_PITCH_68_YAW_293=38, /* Roll: 90, Pitch: 68, Yaw: 293 | */
   MAV_SENSOR_ROTATION_PITCH_315=39, /* Pitch: 315 | */
   MAV_SENSOR_ROTATION_ROLL_90_PITCH_315=40, /* Roll: 90, Pitch: 315 | */
   MAV_SENSOR_ROTATION_CUSTOM=100, /* Custom orientation | */
   MAV_SENSOR_ORIENTATION_ENUM_END=101, /*  | */
} MAV_SENSOR_ORIENTATION;
#endif

/** @brief Bitmask of (optional) autopilot capabilities (64 bit). If a bit is set, the autopilot supports this capability. */
#ifndef HAVE_ENUM_MAV_PROTOCOL_CAPABILITY
#define HAVE_ENUM_MAV_PROTOCOL_CAPABILITY
typedef enum MAV_PROTOCOL_CAPABILITY
{
   MAV_PROTOCOL_CAPABILITY_MISSION_FLOAT=1, /* Autopilot supports MISSION float message type. | */
   MAV_PROTOCOL_CAPABILITY_PARAM_FLOAT=2, /* Autopilot supports the new param float message type. | */
   MAV_PROTOCOL_CAPABILITY_MISSION_INT=4, /* Autopilot supports MISSION_INT scaled integer message type. | */
   MAV_PROTOCOL_CAPABILITY_COMMAND_INT=8, /* Autopilot supports COMMAND_INT scaled integer message type. | */
   MAV_PROTOCOL_CAPABILITY_PARAM_UNION=16, /* Autopilot supports the new param union message type. | */
   MAV_PROTOCOL_CAPABILITY_FTP=32, /* Autopilot supports the new FILE_TRANSFER_PROTOCOL message type. | */
   MAV_PROTOCOL_CAPABILITY_SET_ATTITUDE_TARGET=64, /* Autopilot supports commanding attitude offboard. | */
   MAV_PROTOCOL_CAPABILITY_SET_POSITION_TARGET_LOCAL_NED=128, /* Autopilot supports commanding position and velocity targets in local NED frame. | */
   MAV_PROTOCOL_CAPABILITY_SET_POSITION_TARGET_GLOBAL_INT=256, /* Autopilot supports commanding position and velocity targets in global scaled integers. | */
   MAV_PROTOCOL_CAPABILITY_TERRAIN=512, /* Autopilot supports terrain protocol / data handling. | */
   MAV_PROTOCOL_CAPABILITY_SET_ACTUATOR_TARGET=1024, /* Autopilot supports direct actuator control. | */
   MAV_PROTOCOL_CAPABILITY_FLIGHT_TERMINATION=2048, /* Autopilot supports the flight termination command. | */
   MAV_PROTOCOL_CAPABILITY_COMPASS_CALIBRATION=4096, /* Autopilot supports onboard compass calibration. | */
   MAV_PROTOCOL_CAPABILITY_MAVLINK2=8192, /* Autopilot supports MAVLink version 2. | */
   MAV_PROTOCOL_CAPABILITY_MISSION_FENCE=16384, /* Autopilot supports mission fence protocol. | */
   MAV_PROTOCOL_CAPABILITY_MISSION_RALLY=32768, /* Autopilot supports mission rally point protocol. | */
   MAV_PROTOCOL_CAPABILITY_FLIGHT_INFORMATION=65536, /* Autopilot supports the flight information protocol. | */
   MAV_PROTOCOL_CAPABILITY_ENUM_END=65537, /*  | */
} MAV_PROTOCOL_CAPABILITY;
#endif

/** @brief Type of mission items being requested/sent in mission protocol. */
#ifndef HAVE_ENUM_MAV_MISSION_TYPE
#define HAVE_ENUM_MAV_MISSION_TYPE
typedef enum MAV_MISSION_TYPE
{
   MAV_MISSION_TYPE_MISSION=0, /* Items are mission commands for main mission. | */
   MAV_MISSION_TYPE_FENCE=1, /* Specifies GeoFence area(s). Items are MAV_CMD_FENCE_ GeoFence items. | */
   MAV_MISSION_TYPE_RALLY=2, /* Specifies the rally points for the vehicle. Rally points are alternative RTL points. Items are MAV_CMD_RALLY_POINT rally point items. | */
   MAV_MISSION_TYPE_ALL=255, /* Only used in MISSION_CLEAR_ALL to clear all mission types. | */
   MAV_MISSION_TYPE_ENUM_END=256, /*  | */
} MAV_MISSION_TYPE;
#endif

/** @brief Enumeration of estimator types */
#ifndef HAVE_ENUM_MAV_ESTIMATOR_TYPE
#define HAVE_ENUM_MAV_ESTIMATOR_TYPE
typedef enum MAV_ESTIMATOR_TYPE
{
   MAV_ESTIMATOR_TYPE_NAIVE=1, /* This is a naive estimator without any real covariance feedback. | */
   MAV_ESTIMATOR_TYPE_VISION=2, /* Computer vision based estimate. Might be up to scale. | */
   MAV_ESTIMATOR_TYPE_VIO=3, /* Visual-inertial estimate. | */
   MAV_ESTIMATOR_TYPE_GPS=4, /* Plain GPS estimate. | */
   MAV_ESTIMATOR_TYPE_GPS_INS=5, /* Estimator integrating GPS and inertial sensing. | */
   MAV_ESTIMATOR_TYPE_ENUM_END=6, /*  | */
} MAV_ESTIMATOR_TYPE;
#endif

/** @brief Enumeration of battery types */
#ifndef HAVE_ENUM_MAV_BATTERY_TYPE
#define HAVE_ENUM_MAV_BATTERY_TYPE
typedef enum MAV_BATTERY_TYPE
{
   MAV_BATTERY_TYPE_UNKNOWN=0, /* Not specified. | */
   MAV_BATTERY_TYPE_LIPO=1, /* Lithium polymer battery | */
   MAV_BATTERY_TYPE_LIFE=2, /* Lithium-iron-phosphate battery | */
   MAV_BATTERY_TYPE_LION=3, /* Lithium-ION battery | */
   MAV_BATTERY_TYPE_NIMH=4, /* Nickel metal hydride battery | */
   MAV_BATTERY_TYPE_ENUM_END=5, /*  | */
} MAV_BATTERY_TYPE;
#endif

/** @brief Enumeration of battery functions */
#ifndef HAVE_ENUM_MAV_BATTERY_FUNCTION
#define HAVE_ENUM_MAV_BATTERY_FUNCTION
typedef enum MAV_BATTERY_FUNCTION
{
   MAV_BATTERY_FUNCTION_UNKNOWN=0, /* Battery function is unknown | */
   MAV_BATTERY_FUNCTION_ALL=1, /* Battery supports all flight systems | */
   MAV_BATTERY_FUNCTION_PROPULSION=2, /* Battery for the propulsion system | */
   MAV_BATTERY_FUNCTION_AVIONICS=3, /* Avionics battery | */
   MAV_BATTERY_TYPE_PAYLOAD=4, /* Payload battery | */
   MAV_BATTERY_FUNCTION_ENUM_END=5, /*  | */
} MAV_BATTERY_FUNCTION;
#endif

/** @brief Enumeration for low battery states. */
#ifndef HAVE_ENUM_MAV_BATTERY_CHARGE_STATE
#define HAVE_ENUM_MAV_BATTERY_CHARGE_STATE
typedef enum MAV_BATTERY_CHARGE_STATE
{
   MAV_BATTERY_CHARGE_STATE_UNDEFINED=0, /* Low battery state is not provided | */
   MAV_BATTERY_CHARGE_STATE_OK=1, /* Battery is not in low state. Normal operation. | */
   MAV_BATTERY_CHARGE_STATE_LOW=2, /* Battery state is low, warn and monitor close. | */
   MAV_BATTERY_CHARGE_STATE_CRITICAL=3, /* Battery state is critical, return or abort immediately. | */
   MAV_BATTERY_CHARGE_STATE_EMERGENCY=4, /* Battery state is too low for ordinary abort sequence. Perform fastest possible emergency stop to prevent damage. | */
   MAV_BATTERY_CHARGE_STATE_FAILED=5, /* Battery failed, damage unavoidable. | */
   MAV_BATTERY_CHARGE_STATE_UNHEALTHY=6, /* Battery is diagnosed to be defective or an error occurred, usage is discouraged / prohibited. | */
   MAV_BATTERY_CHARGE_STATE_ENUM_END=7, /*  | */
} MAV_BATTERY_CHARGE_STATE;
#endif

/** @brief Enumeration of VTOL states */
#ifndef HAVE_ENUM_MAV_VTOL_STATE
#define HAVE_ENUM_MAV_VTOL_STATE
typedef enum MAV_VTOL_STATE
{
   MAV_VTOL_STATE_UNDEFINED=0, /* MAV is not configured as VTOL | */
   MAV_VTOL_STATE_TRANSITION_TO_FW=1, /* VTOL is in transition from multicopter to fixed-wing | */
   MAV_VTOL_STATE_TRANSITION_TO_MC=2, /* VTOL is in transition from fixed-wing to multicopter | */
   MAV_VTOL_STATE_MC=3, /* VTOL is in multicopter state | */
   MAV_VTOL_STATE_FW=4, /* VTOL is in fixed-wing state | */
   MAV_VTOL_STATE_ENUM_END=5, /*  | */
} MAV_VTOL_STATE;
#endif

/** @brief Enumeration of landed detector states */
#ifndef HAVE_ENUM_MAV_LANDED_STATE
#define HAVE_ENUM_MAV_LANDED_STATE
typedef enum MAV_LANDED_STATE
{
   MAV_LANDED_STATE_UNDEFINED=0, /* MAV landed state is unknown | */
   MAV_LANDED_STATE_ON_GROUND=1, /* MAV is landed (on ground) | */
   MAV_LANDED_STATE_IN_AIR=2, /* MAV is in air | */
   MAV_LANDED_STATE_TAKEOFF=3, /* MAV currently taking off | */
   MAV_LANDED_STATE_LANDING=4, /* MAV currently landing | */
   MAV_LANDED_STATE_ENUM_END=5, /*  | */
} MAV_LANDED_STATE;
#endif

/** @brief Enumeration of the ADSB altimeter types */
#ifndef HAVE_ENUM_ADSB_ALTITUDE_TYPE
#define HAVE_ENUM_ADSB_ALTITUDE_TYPE
typedef enum ADSB_ALTITUDE_TYPE
{
   ADSB_ALTITUDE_TYPE_PRESSURE_QNH=0, /* Altitude reported from a Baro source using QNH reference | */
   ADSB_ALTITUDE_TYPE_GEOMETRIC=1, /* Altitude reported from a GNSS source | */
   ADSB_ALTITUDE_TYPE_ENUM_END=2, /*  | */
} ADSB_ALTITUDE_TYPE;
#endif

/** @brief ADSB classification for the type of vehicle emitting the transponder signal */
#ifndef HAVE_ENUM_ADSB_EMITTER_TYPE
#define HAVE_ENUM_ADSB_EMITTER_TYPE
typedef enum ADSB_EMITTER_TYPE
{
   ADSB_EMITTER_TYPE_NO_INFO=0, /*  | */
   ADSB_EMITTER_TYPE_LIGHT=1, /*  | */
   ADSB_EMITTER_TYPE_SMALL=2, /*  | */
   ADSB_EMITTER_TYPE_LARGE=3, /*  | */
   ADSB_EMITTER_TYPE_HIGH_VORTEX_LARGE=4, /*  | */
   ADSB_EMITTER_TYPE_HEAVY=5, /*  | */
   ADSB_EMITTER_TYPE_HIGHLY_MANUV=6, /*  | */
   ADSB_EMITTER_TYPE_ROTOCRAFT=7, /*  | */
   ADSB_EMITTER_TYPE_UNASSIGNED=8, /*  | */
   ADSB_EMITTER_TYPE_GLIDER=9, /*  | */
   ADSB_EMITTER_TYPE_LIGHTER_AIR=10, /*  | */
   ADSB_EMITTER_TYPE_PARACHUTE=11, /*  | */
   ADSB_EMITTER_TYPE_ULTRA_LIGHT=12, /*  | */
   ADSB_EMITTER_TYPE_UNASSIGNED2=13, /*  | */
   ADSB_EMITTER_TYPE_UAV=14, /*  | */
   ADSB_EMITTER_TYPE_SPACE=15, /*  | */
   ADSB_EMITTER_TYPE_UNASSGINED3=16, /*  | */
   ADSB_EMITTER_TYPE_EMERGENCY_SURFACE=17, /*  | */
   ADSB_EMITTER_TYPE_SERVICE_SURFACE=18, /*  | */
   ADSB_EMITTER_TYPE_POINT_OBSTACLE=19, /*  | */
   ADSB_EMITTER_TYPE_ENUM_END=20, /*  | */
} ADSB_EMITTER_TYPE;
#endif

/** @brief These flags indicate status such as data validity of each data source. Set = data valid */
#ifndef HAVE_ENUM_ADSB_FLAGS
#define HAVE_ENUM_ADSB_FLAGS
typedef enum ADSB_FLAGS
{
   ADSB_FLAGS_VALID_COORDS=1, /*  | */
   ADSB_FLAGS_VALID_ALTITUDE=2, /*  | */
   ADSB_FLAGS_VALID_HEADING=4, /*  | */
   ADSB_FLAGS_VALID_VELOCITY=8, /*  | */
   ADSB_FLAGS_VALID_CALLSIGN=16, /*  | */
   ADSB_FLAGS_VALID_SQUAWK=32, /*  | */
   ADSB_FLAGS_SIMULATED=64, /*  | */
   ADSB_FLAGS_ENUM_END=65, /*  | */
} ADSB_FLAGS;
#endif

/** @brief Bitmap of options for the MAV_CMD_DO_REPOSITION */
#ifndef HAVE_ENUM_MAV_DO_REPOSITION_FLAGS
#define HAVE_ENUM_MAV_DO_REPOSITION_FLAGS
typedef enum MAV_DO_REPOSITION_FLAGS
{
   MAV_DO_REPOSITION_FLAGS_CHANGE_MODE=1, /* The aircraft should immediately transition into guided. This should not be set for follow me applications | */
   MAV_DO_REPOSITION_FLAGS_ENUM_END=2, /*  | */
} MAV_DO_REPOSITION_FLAGS;
#endif

/** @brief Flags in EKF_STATUS message */
#ifndef HAVE_ENUM_ESTIMATOR_STATUS_FLAGS
#define HAVE_ENUM_ESTIMATOR_STATUS_FLAGS
typedef enum ESTIMATOR_STATUS_FLAGS
{
   ESTIMATOR_ATTITUDE=1, /* True if the attitude estimate is good | */
   ESTIMATOR_VELOCITY_HORIZ=2, /* True if the horizontal velocity estimate is good | */
   ESTIMATOR_VELOCITY_VERT=4, /* True if the  vertical velocity estimate is good | */
   ESTIMATOR_POS_HORIZ_REL=8, /* True if the horizontal position (relative) estimate is good | */
   ESTIMATOR_POS_HORIZ_ABS=16, /* True if the horizontal position (absolute) estimate is good | */
   ESTIMATOR_POS_VERT_ABS=32, /* True if the vertical position (absolute) estimate is good | */
   ESTIMATOR_POS_VERT_AGL=64, /* True if the vertical position (above ground) estimate is good | */
   ESTIMATOR_CONST_POS_MODE=128, /* True if the EKF is in a constant position mode and is not using external measurements (eg GPS or optical flow) | */
   ESTIMATOR_PRED_POS_HORIZ_REL=256, /* True if the EKF has sufficient data to enter a mode that will provide a (relative) position estimate | */
   ESTIMATOR_PRED_POS_HORIZ_ABS=512, /* True if the EKF has sufficient data to enter a mode that will provide a (absolute) position estimate | */
   ESTIMATOR_GPS_GLITCH=1024, /* True if the EKF has detected a GPS glitch | */
   ESTIMATOR_ACCEL_ERROR=2048, /* True if the EKF has detected bad accelerometer data | */
   ESTIMATOR_STATUS_FLAGS_ENUM_END=2049, /*  | */
} ESTIMATOR_STATUS_FLAGS;
#endif

/** @brief  */
#ifndef HAVE_ENUM_MOTOR_TEST_ORDER
#define HAVE_ENUM_MOTOR_TEST_ORDER
typedef enum MOTOR_TEST_ORDER
{
   MOTOR_TEST_ORDER_DEFAULT=0, /* default autopilot motor test method | */
   MOTOR_TEST_ORDER_SEQUENCE=1, /* motor numbers are specified as their index in a predefined vehicle-specific sequence | */
   MOTOR_TEST_ORDER_BOARD=2, /* motor numbers are specified as the output as labeled on the board | */
   MOTOR_TEST_ORDER_ENUM_END=3, /*  | */
} MOTOR_TEST_ORDER;
#endif

/** @brief  */
#ifndef HAVE_ENUM_MOTOR_TEST_THROTTLE_TYPE
#define HAVE_ENUM_MOTOR_TEST_THROTTLE_TYPE
typedef enum MOTOR_TEST_THROTTLE_TYPE
{
   MOTOR_TEST_THROTTLE_PERCENT=0, /* throttle as a percentage from 0 ~ 100 | */
   MOTOR_TEST_THROTTLE_PWM=1, /* throttle as an absolute PWM value (normally in range of 1000~2000) | */
   MOTOR_TEST_THROTTLE_PILOT=2, /* throttle pass-through from pilot's transmitter | */
   MOTOR_TEST_COMPASS_CAL=3, /* per-motor compass calibration test | */
   MOTOR_TEST_THROTTLE_TYPE_ENUM_END=4, /*  | */
} MOTOR_TEST_THROTTLE_TYPE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_GPS_INPUT_IGNORE_FLAGS
#define HAVE_ENUM_GPS_INPUT_IGNORE_FLAGS
typedef enum GPS_INPUT_IGNORE_FLAGS
{
   GPS_INPUT_IGNORE_FLAG_ALT=1, /* ignore altitude field | */
   GPS_INPUT_IGNORE_FLAG_HDOP=2, /* ignore hdop field | */
   GPS_INPUT_IGNORE_FLAG_VDOP=4, /* ignore vdop field | */
   GPS_INPUT_IGNORE_FLAG_VEL_HORIZ=8, /* ignore horizontal velocity field (vn and ve) | */
   GPS_INPUT_IGNORE_FLAG_VEL_VERT=16, /* ignore vertical velocity field (vd) | */
   GPS_INPUT_IGNORE_FLAG_SPEED_ACCURACY=32, /* ignore speed accuracy field | */
   GPS_INPUT_IGNORE_FLAG_HORIZONTAL_ACCURACY=64, /* ignore horizontal accuracy field | */
   GPS_INPUT_IGNORE_FLAG_VERTICAL_ACCURACY=128, /* ignore vertical accuracy field | */
   GPS_INPUT_IGNORE_FLAGS_ENUM_END=129, /*  | */
} GPS_INPUT_IGNORE_FLAGS;
#endif

/** @brief Possible actions an aircraft can take to avoid a collision. */
#ifndef HAVE_ENUM_MAV_COLLISION_ACTION
#define HAVE_ENUM_MAV_COLLISION_ACTION
typedef enum MAV_COLLISION_ACTION
{
   MAV_COLLISION_ACTION_NONE=0, /* Ignore any potential collisions | */
   MAV_COLLISION_ACTION_REPORT=1, /* Report potential collision | */
   MAV_COLLISION_ACTION_ASCEND_OR_DESCEND=2, /* Ascend or Descend to avoid threat | */
   MAV_COLLISION_ACTION_MOVE_HORIZONTALLY=3, /* Move horizontally to avoid threat | */
   MAV_COLLISION_ACTION_MOVE_PERPENDICULAR=4, /* Aircraft to move perpendicular to the collision's velocity vector | */
   MAV_COLLISION_ACTION_RTL=5, /* Aircraft to fly directly back to its launch point | */
   MAV_COLLISION_ACTION_HOVER=6, /* Aircraft to stop in place | */
   MAV_COLLISION_ACTION_ENUM_END=7, /*  | */
} MAV_COLLISION_ACTION;
#endif

/** @brief Aircraft-rated danger from this threat. */
#ifndef HAVE_ENUM_MAV_COLLISION_THREAT_LEVEL
#define HAVE_ENUM_MAV_COLLISION_THREAT_LEVEL
typedef enum MAV_COLLISION_THREAT_LEVEL
{
   MAV_COLLISION_THREAT_LEVEL_NONE=0, /* Not a threat | */
   MAV_COLLISION_THREAT_LEVEL_LOW=1, /* Craft is mildly concerned about this threat | */
   MAV_COLLISION_THREAT_LEVEL_HIGH=2, /* Craft is panicing, and may take actions to avoid threat | */
   MAV_COLLISION_THREAT_LEVEL_ENUM_END=3, /*  | */
} MAV_COLLISION_THREAT_LEVEL;
#endif

/** @brief Source of information about this collision. */
#ifndef HAVE_ENUM_MAV_COLLISION_SRC
#define HAVE_ENUM_MAV_COLLISION_SRC
typedef enum MAV_COLLISION_SRC
{
   MAV_COLLISION_SRC_ADSB=0, /* ID field references ADSB_VEHICLE packets | */
   MAV_COLLISION_SRC_MAVLINK_GPS_GLOBAL_INT=1, /* ID field references MAVLink SRC ID | */
   MAV_COLLISION_SRC_ENUM_END=2, /*  | */
} MAV_COLLISION_SRC;
#endif

/** @brief Type of GPS fix */
#ifndef HAVE_ENUM_GPS_FIX_TYPE
#define HAVE_ENUM_GPS_FIX_TYPE
typedef enum GPS_FIX_TYPE
{
   GPS_FIX_TYPE_NO_GPS=0, /* No GPS connected | */
   GPS_FIX_TYPE_NO_FIX=1, /* No position information, GPS is connected | */
   GPS_FIX_TYPE_2D_FIX=2, /* 2D position | */
   GPS_FIX_TYPE_3D_FIX=3, /* 3D position | */
   GPS_FIX_TYPE_DGPS=4, /* DGPS/SBAS aided 3D position | */
   GPS_FIX_TYPE_RTK_FLOAT=5, /* RTK float, 3D position | */
   GPS_FIX_TYPE_RTK_FIXED=6, /* RTK Fixed, 3D position | */
   GPS_FIX_TYPE_STATIC=7, /* Static fixed, typically used for base stations | */
   GPS_FIX_TYPE_PPP=8, /* PPP, 3D position. | */
   GPS_FIX_TYPE_ENUM_END=9, /*  | */
} GPS_FIX_TYPE;
#endif

/** @brief RTK GPS baseline coordinate system, used for RTK corrections */
#ifndef HAVE_ENUM_RTK_BASELINE_COORDINATE_SYSTEM
#define HAVE_ENUM_RTK_BASELINE_COORDINATE_SYSTEM
typedef enum RTK_BASELINE_COORDINATE_SYSTEM
{
   RTK_BASELINE_COORDINATE_SYSTEM_ECEF=0, /* Earth-centered, Earth-fixed | */
   RTK_BASELINE_COORDINATE_SYSTEM_NED=1, /* North, East, Down | */
   RTK_BASELINE_COORDINATE_SYSTEM_ENUM_END=2, /*  | */
} RTK_BASELINE_COORDINATE_SYSTEM;
#endif

/** @brief Type of landing target */
#ifndef HAVE_ENUM_LANDING_TARGET_TYPE
#define HAVE_ENUM_LANDING_TARGET_TYPE
typedef enum LANDING_TARGET_TYPE
{
   LANDING_TARGET_TYPE_LIGHT_BEACON=0, /* Landing target signaled by light beacon (ex: IR-LOCK) | */
   LANDING_TARGET_TYPE_RADIO_BEACON=1, /* Landing target signaled by radio beacon (ex: ILS, NDB) | */
   LANDING_TARGET_TYPE_VISION_FIDUCIAL=2, /* Landing target represented by a fiducial marker (ex: ARTag) | */
   LANDING_TARGET_TYPE_VISION_OTHER=3, /* Landing target represented by a pre-defined visual shape/feature (ex: X-marker, H-marker, square) | */
   LANDING_TARGET_TYPE_ENUM_END=4, /*  | */
} LANDING_TARGET_TYPE;
#endif

/** @brief Direction of VTOL transition */
#ifndef HAVE_ENUM_VTOL_TRANSITION_HEADING
#define HAVE_ENUM_VTOL_TRANSITION_HEADING
typedef enum VTOL_TRANSITION_HEADING
{
   VTOL_TRANSITION_HEADING_VEHICLE_DEFAULT=0, /* Respect the heading configuration of the vehicle. | */
   VTOL_TRANSITION_HEADING_NEXT_WAYPOINT=1, /* Use the heading pointing towards the next waypoint. | */
   VTOL_TRANSITION_HEADING_TAKEOFF=2, /* Use the heading on takeoff (while sitting on the ground). | */
   VTOL_TRANSITION_HEADING_SPECIFIED=3, /* Use the specified heading in parameter 4. | */
   VTOL_TRANSITION_HEADING_ANY=4, /* Use the current heading when reaching takeoff altitude (potentially facing the wind when weather-vaning is active). | */
   VTOL_TRANSITION_HEADING_ENUM_END=5, /*  | */
} VTOL_TRANSITION_HEADING;
#endif

/** @brief Camera capability flags (Bitmap). */
#ifndef HAVE_ENUM_CAMERA_CAP_FLAGS
#define HAVE_ENUM_CAMERA_CAP_FLAGS
typedef enum CAMERA_CAP_FLAGS
{
   CAMERA_CAP_FLAGS_CAPTURE_VIDEO=1, /* Camera is able to record video. | */
   CAMERA_CAP_FLAGS_CAPTURE_IMAGE=2, /* Camera is able to capture images. | */
   CAMERA_CAP_FLAGS_HAS_MODES=4, /* Camera has separate Video and Image/Photo modes (MAV_CMD_SET_CAMERA_MODE) | */
   CAMERA_CAP_FLAGS_CAN_CAPTURE_IMAGE_IN_VIDEO_MODE=8, /* Camera can capture images while in video mode | */
   CAMERA_CAP_FLAGS_CAN_CAPTURE_VIDEO_IN_IMAGE_MODE=16, /* Camera can capture videos while in Photo/Image mode | */
   CAMERA_CAP_FLAGS_HAS_IMAGE_SURVEY_MODE=32, /* Camera has image survey mode (MAV_CMD_SET_CAMERA_MODE) | */
   CAMERA_CAP_FLAGS_ENUM_END=33, /*  | */
} CAMERA_CAP_FLAGS;
#endif

/** @brief Result from a PARAM_EXT_SET message. */
#ifndef HAVE_ENUM_PARAM_ACK
#define HAVE_ENUM_PARAM_ACK
typedef enum PARAM_ACK
{
   PARAM_ACK_ACCEPTED=0, /* Parameter value ACCEPTED and SET | */
   PARAM_ACK_VALUE_UNSUPPORTED=1, /* Parameter value UNKNOWN/UNSUPPORTED | */
   PARAM_ACK_FAILED=2, /* Parameter failed to set | */
   PARAM_ACK_IN_PROGRESS=3, /* Parameter value received but not yet validated or set. A subsequent PARAM_EXT_ACK will follow once operation is completed with the actual result. These are for parameters that may take longer to set. Instead of waiting for an ACK and potentially timing out, you will immediately receive this response to let you know it was received. | */
   PARAM_ACK_ENUM_END=4, /*  | */
} PARAM_ACK;
#endif

/** @brief Camera Modes. */
#ifndef HAVE_ENUM_CAMERA_MODE
#define HAVE_ENUM_CAMERA_MODE
typedef enum CAMERA_MODE
{
   CAMERA_MODE_IMAGE=0, /* Camera is in image/photo capture mode. | */
   CAMERA_MODE_VIDEO=1, /* Camera is in video capture mode. | */
   CAMERA_MODE_IMAGE_SURVEY=2, /* Camera is in image survey capture mode. It allows for camera controller to do specific settings for surveys. | */
   CAMERA_MODE_ENUM_END=3, /*  | */
} CAMERA_MODE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_MAV_ARM_AUTH_DENIED_REASON
#define HAVE_ENUM_MAV_ARM_AUTH_DENIED_REASON
typedef enum MAV_ARM_AUTH_DENIED_REASON
{
   MAV_ARM_AUTH_DENIED_REASON_GENERIC=0, /* Not a specific reason | */
   MAV_ARM_AUTH_DENIED_REASON_NONE=1, /* Authorizer will send the error as string to GCS | */
   MAV_ARM_AUTH_DENIED_REASON_INVALID_WAYPOINT=2, /* At least one waypoint have a invalid value | */
   MAV_ARM_AUTH_DENIED_REASON_TIMEOUT=3, /* Timeout in the authorizer process(in case it depends on network) | */
   MAV_ARM_AUTH_DENIED_REASON_AIRSPACE_IN_USE=4, /* Airspace of the mission in use by another vehicle, second result parameter can have the waypoint id that caused it to be denied. | */
   MAV_ARM_AUTH_DENIED_REASON_BAD_WEATHER=5, /* Weather is not good to fly | */
   MAV_ARM_AUTH_DENIED_REASON_ENUM_END=6, /*  | */
} MAV_ARM_AUTH_DENIED_REASON;
#endif

/** @brief RC type */
#ifndef HAVE_ENUM_RC_TYPE
#define HAVE_ENUM_RC_TYPE
typedef enum RC_TYPE
{
   RC_TYPE_SPEKTRUM_DSM2=0, /* Spektrum DSM2 | */
   RC_TYPE_SPEKTRUM_DSMX=1, /* Spektrum DSMX | */
   RC_TYPE_ENUM_END=2, /*  | */
} RC_TYPE;
#endif

/** @brief Bitmap to indicate which dimensions should be ignored by the vehicle: a value of 0b0000000000000000 or 0b0000001000000000 indicates that none of the setpoint dimensions should be ignored. If bit 9 is set the floats afx afy afz should be interpreted as force instead of acceleration. */
#ifndef HAVE_ENUM_POSITION_TARGET_TYPEMASK
#define HAVE_ENUM_POSITION_TARGET_TYPEMASK
typedef enum POSITION_TARGET_TYPEMASK
{
   POSITION_TARGET_TYPEMASK_X_IGNORE=1, /* Ignore position x | */
   POSITION_TARGET_TYPEMASK_Y_IGNORE=2, /* Ignore position y | */
   POSITION_TARGET_TYPEMASK_Z_IGNORE=4, /* Ignore position z | */
   POSITION_TARGET_TYPEMASK_VX_IGNORE=8, /* Ignore velocity x | */
   POSITION_TARGET_TYPEMASK_VY_IGNORE=16, /* Ignore velocity y | */
   POSITION_TARGET_TYPEMASK_VZ_IGNORE=32, /* Ignore velocity z | */
   POSITION_TARGET_TYPEMASK_AX_IGNORE=64, /* Ignore acceleration x | */
   POSITION_TARGET_TYPEMASK_AY_IGNORE=128, /* Ignore acceleration y | */
   POSITION_TARGET_TYPEMASK_AZ_IGNORE=256, /* Ignore acceleration z | */
   POSITION_TARGET_TYPEMASK_FORCE_SET=512, /* Use force instead of acceleration | */
   POSITION_TARGET_TYPEMASK_YAW_IGNORE=1024, /* Ignore yaw | */
   POSITION_TARGET_TYPEMASK_YAW_RATE_IGNORE=2048, /* Ignore yaw rate | */
   POSITION_TARGET_TYPEMASK_ENUM_END=2049, /*  | */
} POSITION_TARGET_TYPEMASK;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_heartbeat.h"
#include "./mavlink_msg_sys_status.h"
#include "./mavlink_msg_system_time.h"
#include "./mavlink_msg_ping.h"
#include "./mavlink_msg_change_operator_control.h"
#include "./mavlink_msg_change_operator_control_ack.h"
#include "./mavlink_msg_auth_key.h"
#include "./mavlink_msg_set_mode.h"
#include "./mavlink_msg_param_request_read.h"
#include "./mavlink_msg_param_request_list.h"
#include "./mavlink_msg_param_value.h"
#include "./mavlink_msg_param_set.h"
#include "./mavlink_msg_gps_raw_int.h"
#include "./mavlink_msg_gps_status.h"
#include "./mavlink_msg_scaled_imu.h"
#include "./mavlink_msg_raw_imu.h"
#include "./mavlink_msg_raw_pressure.h"
#include "./mavlink_msg_scaled_pressure.h"
#include "./mavlink_msg_attitude.h"
#include "./mavlink_msg_attitude_quaternion.h"
#include "./mavlink_msg_local_position_ned.h"
#include "./mavlink_msg_global_position_int.h"
#include "./mavlink_msg_rc_channels_scaled.h"
#include "./mavlink_msg_rc_channels_raw.h"
#include "./mavlink_msg_servo_output_raw.h"
#include "./mavlink_msg_mission_request_partial_list.h"
#include "./mavlink_msg_mission_write_partial_list.h"
#include "./mavlink_msg_mission_item.h"
#include "./mavlink_msg_mission_request.h"
#include "./mavlink_msg_mission_set_current.h"
#include "./mavlink_msg_mission_current.h"
#include "./mavlink_msg_mission_request_list.h"
#include "./mavlink_msg_mission_count.h"
#include "./mavlink_msg_mission_clear_all.h"
#include "./mavlink_msg_mission_item_reached.h"
#include "./mavlink_msg_mission_ack.h"
#include "./mavlink_msg_set_gps_global_origin.h"
#include "./mavlink_msg_gps_global_origin.h"
#include "./mavlink_msg_param_map_rc.h"
#include "./mavlink_msg_mission_request_int.h"
#include "./mavlink_msg_safety_set_allowed_area.h"
#include "./mavlink_msg_safety_allowed_area.h"
#include "./mavlink_msg_attitude_quaternion_cov.h"
#include "./mavlink_msg_nav_controller_output.h"
#include "./mavlink_msg_global_position_int_cov.h"
#include "./mavlink_msg_local_position_ned_cov.h"
#include "./mavlink_msg_rc_channels.h"
#include "./mavlink_msg_request_data_stream.h"
#include "./mavlink_msg_data_stream.h"
#include "./mavlink_msg_manual_control.h"
#include "./mavlink_msg_rc_channels_override.h"
#include "./mavlink_msg_mission_item_int.h"
#include "./mavlink_msg_vfr_hud.h"
#include "./mavlink_msg_command_int.h"
#include "./mavlink_msg_command_long.h"
#include "./mavlink_msg_command_ack.h"
#include "./mavlink_msg_manual_setpoint.h"
#include "./mavlink_msg_set_attitude_target.h"
#include "./mavlink_msg_attitude_target.h"
#include "./mavlink_msg_set_position_target_local_ned.h"
#include "./mavlink_msg_position_target_local_ned.h"
#include "./mavlink_msg_set_position_target_global_int.h"
#include "./mavlink_msg_position_target_global_int.h"
#include "./mavlink_msg_local_position_ned_system_global_offset.h"
#include "./mavlink_msg_hil_state.h"
#include "./mavlink_msg_hil_controls.h"
#include "./mavlink_msg_hil_rc_inputs_raw.h"
#include "./mavlink_msg_hil_actuator_controls.h"
#include "./mavlink_msg_optical_flow.h"
#include "./mavlink_msg_global_vision_position_estimate.h"
#include "./mavlink_msg_vision_position_estimate.h"
#include "./mavlink_msg_vision_speed_estimate.h"
#include "./mavlink_msg_vicon_position_estimate.h"
#include "./mavlink_msg_highres_imu.h"
#include "./mavlink_msg_optical_flow_rad.h"
#include "./mavlink_msg_hil_sensor.h"
#include "./mavlink_msg_sim_state.h"
#include "./mavlink_msg_radio_status.h"
#include "./mavlink_msg_file_transfer_protocol.h"
#include "./mavlink_msg_timesync.h"
#include "./mavlink_msg_camera_trigger.h"
#include "./mavlink_msg_hil_gps.h"
#include "./mavlink_msg_hil_optical_flow.h"
#include "./mavlink_msg_hil_state_quaternion.h"
#include "./mavlink_msg_scaled_imu2.h"
#include "./mavlink_msg_log_request_list.h"
#include "./mavlink_msg_log_entry.h"
#include "./mavlink_msg_log_request_data.h"
#include "./mavlink_msg_log_data.h"
#include "./mavlink_msg_log_erase.h"
#include "./mavlink_msg_log_request_end.h"
#include "./mavlink_msg_gps_inject_data.h"
#include "./mavlink_msg_gps2_raw.h"
#include "./mavlink_msg_power_status.h"
#include "./mavlink_msg_serial_control.h"
#include "./mavlink_msg_gps_rtk.h"
#include "./mavlink_msg_gps2_rtk.h"
#include "./mavlink_msg_scaled_imu3.h"
#include "./mavlink_msg_data_transmission_handshake.h"
#include "./mavlink_msg_encapsulated_data.h"
#include "./mavlink_msg_distance_sensor.h"
#include "./mavlink_msg_terrain_request.h"
#include "./mavlink_msg_terrain_data.h"
#include "./mavlink_msg_terrain_check.h"
#include "./mavlink_msg_terrain_report.h"
#include "./mavlink_msg_scaled_pressure2.h"
#include "./mavlink_msg_att_pos_mocap.h"
#include "./mavlink_msg_set_actuator_control_target.h"
#include "./mavlink_msg_actuator_control_target.h"
#include "./mavlink_msg_altitude.h"
#include "./mavlink_msg_resource_request.h"
#include "./mavlink_msg_scaled_pressure3.h"
#include "./mavlink_msg_follow_target.h"
#include "./mavlink_msg_control_system_state.h"
#include "./mavlink_msg_battery_status.h"
#include "./mavlink_msg_autopilot_version.h"
#include "./mavlink_msg_landing_target.h"
#include "./mavlink_msg_estimator_status.h"
#include "./mavlink_msg_wind_cov.h"
#include "./mavlink_msg_gps_input.h"
#include "./mavlink_msg_gps_rtcm_data.h"
#include "./mavlink_msg_high_latency.h"
#include "./mavlink_msg_high_latency2.h"
#include "./mavlink_msg_vibration.h"
#include "./mavlink_msg_home_position.h"
#include "./mavlink_msg_set_home_position.h"
#include "./mavlink_msg_message_interval.h"
#include "./mavlink_msg_extended_sys_state.h"
#include "./mavlink_msg_adsb_vehicle.h"
#include "./mavlink_msg_collision.h"
#include "./mavlink_msg_v2_extension.h"
#include "./mavlink_msg_memory_vect.h"
#include "./mavlink_msg_debug_vect.h"
#include "./mavlink_msg_named_value_float.h"
#include "./mavlink_msg_named_value_int.h"
#include "./mavlink_msg_statustext.h"
#include "./mavlink_msg_debug.h"

// base include


#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 1

#if MAVLINK_THIS_XML_IDX == MAVLINK_PRIMARY_XML_IDX
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_HEARTBEAT, MAVLINK_MESSAGE_INFO_SYS_STATUS, MAVLINK_MESSAGE_INFO_SYSTEM_TIME, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_PING, MAVLINK_MESSAGE_INFO_CHANGE_OPERATOR_CONTROL, MAVLINK_MESSAGE_INFO_CHANGE_OPERATOR_CONTROL_ACK, MAVLINK_MESSAGE_INFO_AUTH_KEY, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_SET_MODE, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_PARAM_REQUEST_READ, MAVLINK_MESSAGE_INFO_PARAM_REQUEST_LIST, MAVLINK_MESSAGE_INFO_PARAM_VALUE, MAVLINK_MESSAGE_INFO_PARAM_SET, MAVLINK_MESSAGE_INFO_GPS_RAW_INT, MAVLINK_MESSAGE_INFO_GPS_STATUS, MAVLINK_MESSAGE_INFO_SCALED_IMU, MAVLINK_MESSAGE_INFO_RAW_IMU, MAVLINK_MESSAGE_INFO_RAW_PRESSURE, MAVLINK_MESSAGE_INFO_SCALED_PRESSURE, MAVLINK_MESSAGE_INFO_ATTITUDE, MAVLINK_MESSAGE_INFO_ATTITUDE_QUATERNION, MAVLINK_MESSAGE_INFO_LOCAL_POSITION_NED, MAVLINK_MESSAGE_INFO_GLOBAL_POSITION_INT, MAVLINK_MESSAGE_INFO_RC_CHANNELS_SCALED, MAVLINK_MESSAGE_INFO_RC_CHANNELS_RAW, MAVLINK_MESSAGE_INFO_SERVO_OUTPUT_RAW, MAVLINK_MESSAGE_INFO_MISSION_REQUEST_PARTIAL_LIST, MAVLINK_MESSAGE_INFO_MISSION_WRITE_PARTIAL_LIST, MAVLINK_MESSAGE_INFO_MISSION_ITEM, MAVLINK_MESSAGE_INFO_MISSION_REQUEST, MAVLINK_MESSAGE_INFO_MISSION_SET_CURRENT, MAVLINK_MESSAGE_INFO_MISSION_CURRENT, MAVLINK_MESSAGE_INFO_MISSION_REQUEST_LIST, MAVLINK_MESSAGE_INFO_MISSION_COUNT, MAVLINK_MESSAGE_INFO_MISSION_CLEAR_ALL, MAVLINK_MESSAGE_INFO_MISSION_ITEM_REACHED, MAVLINK_MESSAGE_INFO_MISSION_ACK, MAVLINK_MESSAGE_INFO_SET_GPS_GLOBAL_ORIGIN, MAVLINK_MESSAGE_INFO_GPS_GLOBAL_ORIGIN, MAVLINK_MESSAGE_INFO_PARAM_MAP_RC, MAVLINK_MESSAGE_INFO_MISSION_REQUEST_INT, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_SAFETY_SET_ALLOWED_AREA, MAVLINK_MESSAGE_INFO_SAFETY_ALLOWED_AREA, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_ATTITUDE_QUATERNION_COV, MAVLINK_MESSAGE_INFO_NAV_CONTROLLER_OUTPUT, MAVLINK_MESSAGE_INFO_GLOBAL_POSITION_INT_COV, MAVLINK_MESSAGE_INFO_LOCAL_POSITION_NED_COV, MAVLINK_MESSAGE_INFO_RC_CHANNELS, MAVLINK_MESSAGE_INFO_REQUEST_DATA_STREAM, MAVLINK_MESSAGE_INFO_DATA_STREAM, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_MANUAL_CONTROL, MAVLINK_MESSAGE_INFO_RC_CHANNELS_OVERRIDE, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_MISSION_ITEM_INT, MAVLINK_MESSAGE_INFO_VFR_HUD, MAVLINK_MESSAGE_INFO_COMMAND_INT, MAVLINK_MESSAGE_INFO_COMMAND_LONG, MAVLINK_MESSAGE_INFO_COMMAND_ACK, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_MANUAL_SETPOINT, MAVLINK_MESSAGE_INFO_SET_ATTITUDE_TARGET, MAVLINK_MESSAGE_INFO_ATTITUDE_TARGET, MAVLINK_MESSAGE_INFO_SET_POSITION_TARGET_LOCAL_NED, MAVLINK_MESSAGE_INFO_POSITION_TARGET_LOCAL_NED, MAVLINK_MESSAGE_INFO_SET_POSITION_TARGET_GLOBAL_INT, MAVLINK_MESSAGE_INFO_POSITION_TARGET_GLOBAL_INT, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET, MAVLINK_MESSAGE_INFO_HIL_STATE, MAVLINK_MESSAGE_INFO_HIL_CONTROLS, MAVLINK_MESSAGE_INFO_HIL_RC_INPUTS_RAW, MAVLINK_MESSAGE_INFO_HIL_ACTUATOR_CONTROLS, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_OPTICAL_FLOW, MAVLINK_MESSAGE_INFO_GLOBAL_VISION_POSITION_ESTIMATE, MAVLINK_MESSAGE_INFO_VISION_POSITION_ESTIMATE, MAVLINK_MESSAGE_INFO_VISION_SPEED_ESTIMATE, MAVLINK_MESSAGE_INFO_VICON_POSITION_ESTIMATE, MAVLINK_MESSAGE_INFO_HIGHRES_IMU, MAVLINK_MESSAGE_INFO_OPTICAL_FLOW_RAD, MAVLINK_MESSAGE_INFO_HIL_SENSOR, MAVLINK_MESSAGE_INFO_SIM_STATE, MAVLINK_MESSAGE_INFO_RADIO_STATUS, MAVLINK_MESSAGE_INFO_FILE_TRANSFER_PROTOCOL, MAVLINK_MESSAGE_INFO_TIMESYNC, MAVLINK_MESSAGE_INFO_CAMERA_TRIGGER, MAVLINK_MESSAGE_INFO_HIL_GPS, MAVLINK_MESSAGE_INFO_HIL_OPTICAL_FLOW, MAVLINK_MESSAGE_INFO_HIL_STATE_QUATERNION, MAVLINK_MESSAGE_INFO_SCALED_IMU2, MAVLINK_MESSAGE_INFO_LOG_REQUEST_LIST, MAVLINK_MESSAGE_INFO_LOG_ENTRY, MAVLINK_MESSAGE_INFO_LOG_REQUEST_DATA, MAVLINK_MESSAGE_INFO_LOG_DATA, MAVLINK_MESSAGE_INFO_LOG_ERASE, MAVLINK_MESSAGE_INFO_LOG_REQUEST_END, MAVLINK_MESSAGE_INFO_GPS_INJECT_DATA, MAVLINK_MESSAGE_INFO_GPS2_RAW, MAVLINK_MESSAGE_INFO_POWER_STATUS, MAVLINK_MESSAGE_INFO_SERIAL_CONTROL, MAVLINK_MESSAGE_INFO_GPS_RTK, MAVLINK_MESSAGE_INFO_GPS2_RTK, MAVLINK_MESSAGE_INFO_SCALED_IMU3, MAVLINK_MESSAGE_INFO_DATA_TRANSMISSION_HANDSHAKE, MAVLINK_MESSAGE_INFO_ENCAPSULATED_DATA, MAVLINK_MESSAGE_INFO_DISTANCE_SENSOR, MAVLINK_MESSAGE_INFO_TERRAIN_REQUEST, MAVLINK_MESSAGE_INFO_TERRAIN_DATA, MAVLINK_MESSAGE_INFO_TERRAIN_CHECK, MAVLINK_MESSAGE_INFO_TERRAIN_REPORT, MAVLINK_MESSAGE_INFO_SCALED_PRESSURE2, MAVLINK_MESSAGE_INFO_ATT_POS_MOCAP, MAVLINK_MESSAGE_INFO_SET_ACTUATOR_CONTROL_TARGET, MAVLINK_MESSAGE_INFO_ACTUATOR_CONTROL_TARGET, MAVLINK_MESSAGE_INFO_ALTITUDE, MAVLINK_MESSAGE_INFO_RESOURCE_REQUEST, MAVLINK_MESSAGE_INFO_SCALED_PRESSURE3, MAVLINK_MESSAGE_INFO_FOLLOW_TARGET, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_CONTROL_SYSTEM_STATE, MAVLINK_MESSAGE_INFO_BATTERY_STATUS, MAVLINK_MESSAGE_INFO_AUTOPILOT_VERSION, MAVLINK_MESSAGE_INFO_LANDING_TARGET, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_ESTIMATOR_STATUS, MAVLINK_MESSAGE_INFO_WIND_COV, MAVLINK_MESSAGE_INFO_GPS_INPUT, MAVLINK_MESSAGE_INFO_GPS_RTCM_DATA, MAVLINK_MESSAGE_INFO_HIGH_LATENCY, MAVLINK_MESSAGE_INFO_HIGH_LATENCY2, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_VIBRATION, MAVLINK_MESSAGE_INFO_HOME_POSITION, MAVLINK_MESSAGE_INFO_SET_HOME_POSITION, MAVLINK_MESSAGE_INFO_MESSAGE_INTERVAL, MAVLINK_MESSAGE_INFO_EXTENDED_SYS_STATE, MAVLINK_MESSAGE_INFO_ADSB_VEHICLE, MAVLINK_MESSAGE_INFO_COLLISION, MAVLINK_MESSAGE_INFO_V2_EXTENSION, MAVLINK_MESSAGE_INFO_MEMORY_VECT, MAVLINK_MESSAGE_INFO_DEBUG_VECT, MAVLINK_MESSAGE_INFO_NAMED_VALUE_FLOAT, MAVLINK_MESSAGE_INFO_NAMED_VALUE_INT, MAVLINK_MESSAGE_INFO_STATUSTEXT, MAVLINK_MESSAGE_INFO_DEBUG, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}}
# define MAVLINK_MESSAGE_NAMES {{ "ACTUATOR_CONTROL_TARGET", 140 }, { "ADSB_VEHICLE", 246 }, { "ALTITUDE", 141 }, { "ATTITUDE", 30 }, { "ATTITUDE_QUATERNION", 31 }, { "ATTITUDE_QUATERNION_COV", 61 }, { "ATTITUDE_TARGET", 83 }, { "ATT_POS_MOCAP", 138 }, { "AUTH_KEY", 7 }, { "AUTOPILOT_VERSION", 148 }, { "BATTERY_STATUS", 147 }, { "CAMERA_TRIGGER", 112 }, { "CHANGE_OPERATOR_CONTROL", 5 }, { "CHANGE_OPERATOR_CONTROL_ACK", 6 }, { "COLLISION", 247 }, { "COMMAND_ACK", 77 }, { "COMMAND_INT", 75 }, { "COMMAND_LONG", 76 }, { "CONTROL_SYSTEM_STATE", 146 }, { "DATA_STREAM", 67 }, { "DATA_TRANSMISSION_HANDSHAKE", 130 }, { "DEBUG", 254 }, { "DEBUG_VECT", 250 }, { "DISTANCE_SENSOR", 132 }, { "ENCAPSULATED_DATA", 131 }, { "ESTIMATOR_STATUS", 230 }, { "EXTENDED_SYS_STATE", 245 }, { "FILE_TRANSFER_PROTOCOL", 110 }, { "FOLLOW_TARGET", 144 }, { "GLOBAL_POSITION_INT", 33 }, { "GLOBAL_POSITION_INT_COV", 63 }, { "GLOBAL_VISION_POSITION_ESTIMATE", 101 }, { "GPS2_RAW", 124 }, { "GPS2_RTK", 128 }, { "GPS_GLOBAL_ORIGIN", 49 }, { "GPS_INJECT_DATA", 123 }, { "GPS_INPUT", 232 }, { "GPS_RAW_INT", 24 }, { "GPS_RTCM_DATA", 233 }, { "GPS_RTK", 127 }, { "GPS_STATUS", 25 }, { "HEARTBEAT", 0 }, { "HIGHRES_IMU", 105 }, { "HIGH_LATENCY", 234 }, { "HIGH_LATENCY2", 235 }, { "HIL_ACTUATOR_CONTROLS", 93 }, { "HIL_CONTROLS", 91 }, { "HIL_GPS", 113 }, { "HIL_OPTICAL_FLOW", 114 }, { "HIL_RC_INPUTS_RAW", 92 }, { "HIL_SENSOR", 107 }, { "HIL_STATE", 90 }, { "HIL_STATE_QUATERNION", 115 }, { "HOME_POSITION", 242 }, { "LANDING_TARGET", 149 }, { "LOCAL_POSITION_NED", 32 }, { "LOCAL_POSITION_NED_COV", 64 }, { "LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET", 89 }, { "LOG_DATA", 120 }, { "LOG_ENTRY", 118 }, { "LOG_ERASE", 121 }, { "LOG_REQUEST_DATA", 119 }, { "LOG_REQUEST_END", 122 }, { "LOG_REQUEST_LIST", 117 }, { "MANUAL_CONTROL", 69 }, { "MANUAL_SETPOINT", 81 }, { "MEMORY_VECT", 249 }, { "MESSAGE_INTERVAL", 244 }, { "MISSION_ACK", 47 }, { "MISSION_CLEAR_ALL", 45 }, { "MISSION_COUNT", 44 }, { "MISSION_CURRENT", 42 }, { "MISSION_ITEM", 39 }, { "MISSION_ITEM_INT", 73 }, { "MISSION_ITEM_REACHED", 46 }, { "MISSION_REQUEST", 40 }, { "MISSION_REQUEST_INT", 51 }, { "MISSION_REQUEST_LIST", 43 }, { "MISSION_REQUEST_PARTIAL_LIST", 37 }, { "MISSION_SET_CURRENT", 41 }, { "MISSION_WRITE_PARTIAL_LIST", 38 }, { "NAMED_VALUE_FLOAT", 251 }, { "NAMED_VALUE_INT", 252 }, { "NAV_CONTROLLER_OUTPUT", 62 }, { "OPTICAL_FLOW", 100 }, { "OPTICAL_FLOW_RAD", 106 }, { "PARAM_MAP_RC", 50 }, { "PARAM_REQUEST_LIST", 21 }, { "PARAM_REQUEST_READ", 20 }, { "PARAM_SET", 23 }, { "PARAM_VALUE", 22 }, { "PING", 4 }, { "POSITION_TARGET_GLOBAL_INT", 87 }, { "POSITION_TARGET_LOCAL_NED", 85 }, { "POWER_STATUS", 125 }, { "RADIO_STATUS", 109 }, { "RAW_IMU", 27 }, { "RAW_PRESSURE", 28 }, { "RC_CHANNELS", 65 }, { "RC_CHANNELS_OVERRIDE", 70 }, { "RC_CHANNELS_RAW", 35 }, { "RC_CHANNELS_SCALED", 34 }, { "REQUEST_DATA_STREAM", 66 }, { "RESOURCE_REQUEST", 142 }, { "SAFETY_ALLOWED_AREA", 55 }, { "SAFETY_SET_ALLOWED_AREA", 54 }, { "SCALED_IMU", 26 }, { "SCALED_IMU2", 116 }, { "SCALED_IMU3", 129 }, { "SCALED_PRESSURE", 29 }, { "SCALED_PRESSURE2", 137 }, { "SCALED_PRESSURE3", 143 }, { "SERIAL_CONTROL", 126 }, { "SERVO_OUTPUT_RAW", 36 }, { "SET_ACTUATOR_CONTROL_TARGET", 139 }, { "SET_ATTITUDE_TARGET", 82 }, { "SET_GPS_GLOBAL_ORIGIN", 48 }, { "SET_HOME_POSITION", 243 }, { "SET_MODE", 11 }, { "SET_POSITION_TARGET_GLOBAL_INT", 86 }, { "SET_POSITION_TARGET_LOCAL_NED", 84 }, { "SIM_STATE", 108 }, { "STATUSTEXT", 253 }, { "SYSTEM_TIME", 2 }, { "SYS_STATUS", 1 }, { "TERRAIN_CHECK", 135 }, { "TERRAIN_DATA", 134 }, { "TERRAIN_REPORT", 136 }, { "TERRAIN_REQUEST", 133 }, { "TIMESYNC", 111 }, { "V2_EXTENSION", 248 }, { "VFR_HUD", 74 }, { "VIBRATION", 241 }, { "VICON_POSITION_ESTIMATE", 104 }, { "VISION_POSITION_ESTIMATE", 102 }, { "VISION_SPEED_ESTIMATE", 103 }, { "WIND_COV", 231 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_COMMON_H
