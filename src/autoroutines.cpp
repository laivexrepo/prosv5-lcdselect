#include "main.h"
#include "portdef.h"
/**
 * This is where all the various autonomous routines are located
 * and subsequently called by the autonomous() selector based on LCD input
 **/

using namespace okapi;

auto driveAuto = ChassisControllerFactory::create(
							 LEFT_DRIVE, -RIGHT_DRIVE,
							 AbstractMotor::gearset::green,
							 {4_in, 11.5_in}
						 );

/*auto liftControlAuto = AsyncControllerFactory::posIntegrated(
              {LIFT_MOTOR_ONE, LIFT_MOTOR_TWO, -LIFT_MOTOR_THREE}
); */

// because I have only oen motor plugged in for testing the above controller is
// commented out - otherwise it never complets as it wants to run PID on all three
// motors but the other two never complete.....

auto liftControlAuto = AsyncControllerFactory::posIntegrated(
              LIFT_MOTOR_ONE
);

// Motor control and parameter setting for LIFT motors
/* MotorGroup liftGroupAuto({LIFT_MOTOR_ONE,LIFT_MOTOR_TWO, -LIFT_MOTOR_THREE}); */

// above motor group commented out as there is only one motor being used for
// testing
MotorGroup liftGroupAuto({LIFT_MOTOR_ONE});

/* std::shared_ptr<ChassisControllerFactory>createPtr(LEFT_DRIVE, -RIGHT_DRIVE,
   AbstractMotor::gearset::green,
   {4_in, 11.5_in}
);
*/

void skillRun() {
  pros::lcd::print(2, "Auto:  skillRun");
  if(DEBUG_ON) {
    std::cout << "Running Auto - SkillRun Code " << "\n";
  }
  driveAuto.moveDistance(12_in);
  if(DEBUG_ON) {
    std::cout << "Motor Position: " << liftGroupAuto.getPosition() << "\n";
  }
  //driveAuto.waitUntilSettled();
  liftControlAuto.setTarget(LIFT_HIGH_POLE);
  if(DEBUG_ON) {
    liftControlAuto.waitUntilSettled();                 // this causes all next
                                                        // moves to be blocked until lift complets
    std::cout << "Motor Position: " << liftGroupAuto.getPosition() << "\n";
  }

    driveAuto.moveDistance(12_in);
    driveAuto.turnAngleAsync(90);
};

void autoRedLeft() {
  pros::lcd::print(2, "Auto:  autoRedLeft");

};

void autoBlueLeft() {
  pros::lcd::print(2, "Auto:  autoBlueLeft");

};

void autoRedRight() {
  pros::lcd::print(2, "Auto:  autoRedRight");

};

void autoBlueRight() {
  pros::lcd::print(2, "Auto:  autoBlueRight");

};
