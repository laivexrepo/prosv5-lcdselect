#include "main.h"
#include "portdef.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
using namespace okapi;

// Chassis Controller - lets us drive the robot around with open- or closed-loop control
auto drive = ChassisControllerFactory::create(
							 LEFT_DRIVE, -RIGHT_DRIVE,
							 AbstractMotor::gearset::green,
							 {4_in, 11.5_in}
						 );
/* NOTE: '0' position of encoder is set for the position the motor is in whenever
	 first powered up! '0' position can currentky not be adjusted - bug in OpakiLib being fixed
*/
auto liftControl = AsyncControllerFactory::posIntegrated({LIFT_MOTOR_ONE, LIFT_MOTOR_TWO, -LIFT_MOTOR_THREE});


// Motor control and parameter setting for LIFT motors
MotorGroup liftGroup({LIFT_MOTOR_ONE,LIFT_MOTOR_TWO, -LIFT_MOTOR_THREE});	// creat motor object to set
																												// motor parameters
		// gearing is required to have correct
																												// encoder control green 18:1 gear set
																												// Master controller by default

Controller masterController(ControllerId::master);			// oakpi remote control object - different
																																																								// then PROS object.

void opcontrol() {
  // CLEAN LCD first
	pros::lcd::clear_line(1);
	pros::lcd::clear_line(2);
	pros::lcd::clear_line(3);
	pros::lcd::clear_line(4);
	pros::lcd::clear_line(5);

	pros::lcd::set_text(1, "Running in Operator Control Mode");

	if(DEBUG_ON){
		std::cout << "Motor Torque: " << liftGroup.getTorque() << "\n";	// must open console
																																		// to V5 to see output
	}
	liftGroup.setGearing(AbstractMotor::gearset::green);
	liftControl.setMaxVelocity(200);				// maximum speed - this is no longer
																					// optimum torgue - which is at about 100rpm

  while(1) {
		// Tank drive with left and right sticks
		drive.tank(masterController.getAnalog(ControllerAnalog::leftY),
						 masterController.getAnalog(ControllerAnalog::rightY));

 		if(masterController.getDigital(ControllerDigital::R1)){
	 		liftControl.setTarget(LIFT_HIGH_POLE);								// degrees of encode rotations to
																							    // to move lift to
	 		//liftControl.waitUntilSettled();						// motion is needs to complete before task is freed
	    if(DEBUG_ON) {
		    std::cout << "Motor Position: " << liftGroup.getPosition() << "\n";
	    }
    } else if(masterController.getDigital(ControllerDigital::R2)){
	     liftControl.setTarget(LIFT_FULL_RETRACT);			// return to 0 position of encoder
	     //liftControl.waitUntilSettled();
	     // liftControl.tarePosition();		// reset Encoder to 0 position
			 if(DEBUG_ON) {
			 	std::cout << "Motor Position: " << liftGroup.getPosition() << "\n";
			 }
    } else {
			 // No button pressed so we do nothing. USELESS but for teaching purpose here
		}
    pros::delay(20);
	}
}
