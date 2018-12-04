#ifndef _PORTDEF_H_
#define _PORTDEF_H_

// V5 port definition file
// ----------- MOTOR Ports assignement -------------
#define LIFT_MOTOR_ONE 7
#define LIFT_MOTOR_TWO 8
#define LIFT_MOTOR_THREE 9    // must run in REVERSE

#define LEFT_DRIVE 1
#define RIGHT_DRIVE 10

#define CAP_ROTATE 20

// ----------- Radio and Controllers ---------------
#define VEX_RADIO 21

// ------------ Vision Sensors ---------------------
#define VISION_ONE 14

// ----------- LEGACY port assignements ------------

// ----------- GLOBAL DEBUGGING Variables ----------
#define DEBUG_ON true

// ----------- SETTINGS FOR AUTO LIFT CONTROL -------
#define LIFT_FULL_RETRACT 0       // fully down Position
#define LIFT_LOW_POLE 2750        // encoder target ticks for low scoring pole
#define LIFT_HIGH_POLE 4230      // encoder target ticks for high scoring pole


#endif
