// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING
//
//  DO NOT EDIT this file to adjust your configuration.  Create your own
//  APM_Config.h and use APM_Config.h.example as a reference.
//
// WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING
///
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Default and automatic configuration details.
//
// Notes for maintainers:
//
// - Try to keep this file organised in the same order as APM_Config.h.example
//

#include "defines.h"

///
/// DO NOT EDIT THIS INCLUDE - if you want to make a local change, make that
/// change in your local copy of APM_Config.h.
///
#include "APM_Config.h"  // <== THIS INCLUDE, DO NOT EDIT IT. EVER.
///
/// DO NOT EDIT THIS INCLUDE - if you want to make a local change, make that
/// change in your local copy of APM_Config.h.
///

// Just so that it's completely clear...
#define ENABLED			1
#define DISABLED		0

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// HARDWARE CONFIGURATION AND CONNECTIONS
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// FRAME_CONFIG
//
#ifndef FRAME_CONFIG
# define FRAME_CONFIG		QUAD_FRAME
#endif
#ifndef FRAME_ORIENTATION
# define FRAME_ORIENTATION		PLUS_FRAME
#endif


//////////////////////////////////////////////////////////////////////////////
// Sonar
//
#ifndef SONAR_PIN
# define SONAR_PIN		AP_RANGEFINDER_PITOT_TUBE
#endif

//////////////////////////////////////////////////////////////////////////////
// AIRSPEED_SENSOR
// AIRSPEED_RATIO
//
#ifndef AIRSPEED_SENSOR
# define AIRSPEED_SENSOR		DISABLED
#endif
#ifndef AIRSPEED_RATIO
# define AIRSPEED_RATIO			1.9936		// Note - this varies from the value in ArduPilot due to the difference in ADC resolution
#endif

//////////////////////////////////////////////////////////////////////////////
// HIL_PROTOCOL                             OPTIONAL
// HIL_MODE                                 OPTIONAL
// HIL_PORT                                 OPTIONAL

#ifndef HIL_MODE
#define HIL_MODE	HIL_MODE_DISABLED
#endif

#ifndef HIL_PROTOCOL
#define HIL_PROTOCOL	HIL_PROTOCOL_MAVLINK
#endif

#ifndef HIL_PORT
#define HIL_PORT 0
#endif

#if HIL_MODE != HIL_MODE_DISABLED	// we are in HIL mode

 # undef GPS_PROTOCOL
 # define GPS_PROTOCOL GPS_PROTOCOL_NONE

#endif


// If we are in XPlane, diasble the mag
#if HIL_MODE != HIL_MODE_DISABLED // we are in HIL mode

 // check xplane settings
 #if HIL_PROTOCOL == HIL_PROTOCOL_XPLANE

  // MAGNETOMETER not supported by XPLANE
  # undef MAGNETOMETER
  # define MAGNETOMETER			DISABLED

  # if HIL_MODE != HIL_MODE_ATTITUDE
  #  error HIL_PROTOCOL_XPLANE requires HIL_MODE_ATTITUDE
  # endif

 #endif
#endif

//////////////////////////////////////////////////////////////////////////////
// GPS_PROTOCOL
//
// Note that this test must follow the HIL_PROTOCOL block as the HIL
// setup may override the GPS configuration.
//
#ifndef GPS_PROTOCOL
# define GPS_PROTOCOL 		GPS_PROTOCOL_AUTO
#endif

//////////////////////////////////////////////////////////////////////////////
// GCS_PROTOCOL
// GCS_PORT
//
#ifndef GCS_PROTOCOL
# define GCS_PROTOCOL			GCS_PROTOCOL_MAVLINK
#endif

//Chris: Commenting out assignment of GCS to port 3 because it kills MAVLink on Port 0
#ifndef GCS_PORT
# define GCS_PORT			3
#endif

#ifndef MAV_SYSTEM_ID
# define MAV_SYSTEM_ID		1
#endif

//////////////////////////////////////////////////////////////////////////////
// Serial port speeds.
//
#ifndef SERIAL0_BAUD
# define SERIAL0_BAUD			115200
#endif
#ifndef SERIAL3_BAUD
# define SERIAL3_BAUD			 57600
#endif


//////////////////////////////////////////////////////////////////////////////
// Battery monitoring
//
#ifndef BATTERY_EVENT
# define BATTERY_EVENT			DISABLED
#endif
#ifndef LOW_VOLTAGE
# define LOW_VOLTAGE			9.6
#endif
#ifndef VOLT_DIV_RATIO
# define VOLT_DIV_RATIO			3.56
#endif

#ifndef CURR_AMP_PER_VOLT
# define CURR_AMP_PER_VOLT		27.32
#endif
#ifndef CURR_AMPS_OFFSET
# define CURR_AMPS_OFFSET		0.0
#endif
#ifndef HIGH_DISCHARGE
# define HIGH_DISCHARGE		1760
#endif

//////////////////////////////////////////////////////////////////////////////
// INPUT_VOLTAGE
//
#ifndef INPUT_VOLTAGE
# define INPUT_VOLTAGE			5.0
#endif

//////////////////////////////////////////////////////////////////////////////
//  MAGNETOMETER
#ifndef MAGNETOMETER
# define MAGNETOMETER			DISABLED
#endif
#ifndef MAG_ORIENTATION
# define MAG_ORIENTATION		AP_COMPASS_COMPONENTS_DOWN_PINS_FORWARD
#endif


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// RADIO CONFIGURATION
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// FLIGHT_MODE
//

#if !defined(FLIGHT_MODE_1)
# define FLIGHT_MODE_1			STABILIZE
#endif
#if !defined(FLIGHT_MODE_2)
# define FLIGHT_MODE_2			STABILIZE
#endif
#if !defined(FLIGHT_MODE_3)
# define FLIGHT_MODE_3			STABILIZE
#endif
#if !defined(FLIGHT_MODE_4)
# define FLIGHT_MODE_4			STABILIZE
#endif
#if !defined(FLIGHT_MODE_5)
# define FLIGHT_MODE_5			STABILIZE
#endif
#if !defined(FLIGHT_MODE_6)
# define FLIGHT_MODE_6			STABILIZE
#endif


//////////////////////////////////////////////////////////////////////////////
// THROTTLE_FAILSAFE
// THROTTLE_FS_VALUE
// THROTTLE_FAILSAFE_ACTION
//
#ifndef THROTTLE_FAILSAFE
# define THROTTLE_FAILSAFE			DISABLED
#endif
#ifndef THROTTE_FS_VALUE
# define THROTTLE_FS_VALUE			975
#endif
#ifndef THROTTLE_FAILSAFE_ACTION
# define THROTTLE_FAILSAFE_ACTION	2
#endif


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// STARTUP BEHAVIOUR
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// GROUND_START_DELAY
//
#ifndef GROUND_START_DELAY
# define GROUND_START_DELAY		0
#endif


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// FLIGHT AND NAVIGATION CONTROL
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// Y6 Support

#ifndef Y6_MOTOR_SCALER
# define Y6_MOTOR_SCALER	0.92
#endif

//////////////////////////////////////////////////////////////////////////////
// ACRO Rate Control

#ifndef ACRO_RATE_ROLL_P
# define ACRO_RATE_ROLL_P         .190
#endif
#ifndef ACRO_RATE_ROLL_I
# define ACRO_RATE_ROLL_I         0.0
#endif
#ifndef ACRO_RATE_ROLL_D
# define ACRO_RATE_ROLL_D         0.0
#endif
#ifndef ACRO_RATE_ROLL_IMAX
# define ACRO_RATE_ROLL_IMAX	 20
#endif

#ifndef ACRO_RATE_PITCH_P
# define ACRO_RATE_PITCH_P         .190
#endif
#ifndef ACRO_RATE_PITCH_I
# define ACRO_RATE_PITCH_I         0.0
#endif
#ifndef ACRO_RATE_PITCH_D
# define ACRO_RATE_PITCH_D         0.0
#endif
#ifndef ACRO_RATE_PITCH_IMAX
# define ACRO_RATE_PITCH_IMAX   20
#endif

#ifndef ACRO_RATE_YAW_P
# define ACRO_RATE_YAW_P         .13			// used to control response in turning
#endif
#ifndef ACRO_RATE_YAW_I
# define ACRO_RATE_YAW_I         0.0
#endif
#ifndef ACRO_RATE_YAW_D
# define ACRO_RATE_YAW_D         0.00		//
#endif
#ifndef ACRO_RATE_YAW_IMAX
# define ACRO_RATE_YAW_IMAX   0
#endif

#ifndef ACRO_RATE_TRIGGER
# define ACRO_RATE_TRIGGER   0
#endif


//////////////////////////////////////////////////////////////////////////////
// STABILZE Angle Control
//
#ifndef STABILIZE_ROLL_P
# define STABILIZE_ROLL_P 		0.54 // .48 = 4.0 NG, .54 = 4.5 NG
#endif
#ifndef STABILIZE_ROLL_I
# define STABILIZE_ROLL_I 		0.025		//
#endif
#ifndef STABILIZE_ROLL_D
# define STABILIZE_ROLL_D 		0.12
#endif
#ifndef STABILIZE_ROLL_IMAX
# define STABILIZE_ROLL_IMAX 	.5		// degrees * 100
#endif

#ifndef STABILIZE_PITCH_P
# define STABILIZE_PITCH_P		0.48
#endif
#ifndef STABILIZE_PITCH_I
# define STABILIZE_PITCH_I		0.025
#endif
#ifndef STABILIZE_PITCH_D
# define STABILIZE_PITCH_D		0.12
#endif
#ifndef STABILIZE_PITCH_IMAX
# define STABILIZE_PITCH_IMAX	.5		// degrees * 100
#endif

//////////////////////////////////////////////////////////////////////////////
// YAW Control
//
#ifndef  YAW_P
# define YAW_P					0.4			// increase for more aggressive Yaw Hold, decrease if it's bouncy
#endif
#ifndef  YAW_I
# define YAW_I					0.00		// increased to .1 to try and get over user's steady state error caused by poor balance
#endif
#ifndef  YAW_D
# define YAW_D					0.05		// Trying a lower value to prevent odd behavior
#endif
#ifndef  YAW_IMAX
# define YAW_IMAX				0			//	Always 0
#endif

//////////////////////////////////////////////////////////////////////////////
// Autopilot control limits
//
// how much to we pitch towards the target
#ifndef PITCH_MAX
# define PITCH_MAX				18			// degrees
#endif


//////////////////////////////////////////////////////////////////////////////
// Navigation control gains
//
#ifndef NAV_LOITER_P
# define NAV_LOITER_P			2.5			// upped to be a bit more aggressive
#endif
#ifndef NAV_LOITER_I
# define NAV_LOITER_I			0.05		// upped a bit to deal with wind faster
#endif
#ifndef NAV_LOITER_D
# define NAV_LOITER_D			0.00
#endif
#ifndef NAV_LOITER_IMAX
# define NAV_LOITER_IMAX		20			// 20°
#endif

#if NAV_TEST == 1	// 0 = traditional, 1 = rate controlled
	#ifndef NAV_WP_P
	# define NAV_WP_P				3.0			// for 4.5 ms error = 13.5 pitch
	#endif
	#ifndef NAV_WP_I
	# define NAV_WP_I				0.5			// this is a fast ramp up
	#endif
	#ifndef NAV_WP_D
	# define NAV_WP_D				0			// slight dampening of a few degrees at most
	#endif
	#ifndef NAV_WP_IMAX
	# define NAV_WP_IMAX			40			// degrees
	#endif
#else
	#ifndef NAV_WP_P
	# define NAV_WP_P				4.0
	#endif
	#ifndef NAV_WP_I
	# define NAV_WP_I				0.15			// leave 0
	#endif
	#ifndef NAV_WP_D
	# define NAV_WP_D				10			// not sure about at all
	#endif
	#ifndef NAV_WP_IMAX
	# define NAV_WP_IMAX			20			// 20 degrees
	#endif
#endif

//////////////////////////////////////////////////////////////////////////////
// Throttle control gains
//
#ifndef THROTTLE_BARO_P
# define THROTTLE_BARO_P		0.3
#endif
#ifndef THROTTLE_BARO_I
# define THROTTLE_BARO_I		0.1
#endif
#ifndef THROTTLE_BARO_D
# define THROTTLE_BARO_D		0.03
#endif
#ifndef THROTTLE_BARO_IMAX
# define THROTTLE_BARO_IMAX		50
#endif


#ifndef THROTTLE_SONAR_P
# define THROTTLE_SONAR_P		0.8		// upped from .5
#endif
#ifndef THROTTLE_SONAR_I
# define THROTTLE_SONAR_I		0.1
#endif
#ifndef THROTTLE_SONAR_D
# define THROTTLE_SONAR_D		0.05
#endif
#ifndef THROTTLE_SONAR_IMAX
# define THROTTLE_SONAR_IMAX	60
#endif


//////////////////////////////////////////////////////////////////////////////
// Crosstrack compensation
//
#ifndef XTRACK_GAIN
# define XTRACK_GAIN          5 // deg/m
#endif
#ifndef XTRACK_ENTRY_ANGLE
# define XTRACK_ENTRY_ANGLE   40 // deg
#endif


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// DEBUGGING
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// DEBUG_LEVEL
//
#ifndef DEBUG_LEVEL
# define DEBUG_LEVEL SEVERITY_LOW
#endif


#ifndef CHANNEL_6_TUNING
# define CHANNEL_6_TUNING CH6_NONE
#endif

//////////////////////////////////////////////////////////////////////////////
// Dataflash logging control
//
#ifndef LOG_ATTITUDE_FAST
# define LOG_ATTITUDE_FAST		DISABLED
#endif
#ifndef LOG_ATTITUDE_MED
# define LOG_ATTITUDE_MED 		ENABLED
#endif
#ifndef LOG_GPS
# define LOG_GPS 				ENABLED
#endif
#ifndef LOG_PM
# define LOG_PM 				ENABLED
#endif
#ifndef LOG_CTUN
# define LOG_CTUN				DISABLED
#endif
#ifndef LOG_NTUN
# define LOG_NTUN				DISABLED
#endif
#ifndef LOG_MODE
# define LOG_MODE				ENABLED
#endif
#ifndef LOG_RAW
# define LOG_RAW				DISABLED
#endif
#ifndef LOG_CMD
# define LOG_CMD				ENABLED
#endif
#ifndef LOG_CURRENT
# define LOG_CURRENT			DISABLED
#endif

#ifndef DEBUG_PORT
# define DEBUG_PORT 0
#endif

#if DEBUG_PORT == 0
# define SendDebug_P(a) Serial.print_P(PSTR(a))
# define SendDebugln_P(a) Serial.println_P(PSTR(a))
# define SendDebug Serial.print
# define SendDebugln Serial.println
#elif DEBUG_PORT == 1
# define SendDebug_P(a) Serial1.print_P(PSTR(a))
# define SendDebugln_P(a) Serial1.println_P(PSTR(a))
# define SendDebug Serial1.print
# define SendDebugln Serial1.println
#elif DEBUG_PORT == 2
# define SendDebug_P(a) Serial2.print_P(PSTR(a))
# define SendDebugln_P(a) Serial2.println_P(PSTR(a))
# define SendDebug Serial2.print
# define SendDebugln Serial2.println
#elif DEBUG_PORT == 3
# define SendDebug_P(a) Serial3.print_P(PSTR(a))
# define SendDebugln_P(a) Serial3.println_P(PSTR(a))
# define SendDebug Serial3.print
# define SendDebugln Serial3.println
#endif

//////////////////////////////////////////////////////////////////////////////
// Navigation defaults
//
#ifndef WP_RADIUS_DEFAULT
# define WP_RADIUS_DEFAULT		3
#endif

#ifndef LOITER_RADIUS_DEFAULT
# define LOITER_RADIUS_DEFAULT 10
#endif

#ifndef ALT_HOLD_HOME
# define ALT_HOLD_HOME 8
#endif

#ifndef USE_CURRENT_ALT
# define USE_CURRENT_ALT FALSE
#endif


//////////////////////////////////////////////////////////////////////////////
// RC override
//
#ifndef ALLOW_RC_OVERRIDE
# define ALLOW_RC_OVERRIDE DISABLED
#endif
