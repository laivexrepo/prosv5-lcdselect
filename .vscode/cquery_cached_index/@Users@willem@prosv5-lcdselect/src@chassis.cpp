#include "main.h"
#include "portdef.h"

/**
 * This is where all the various chassis control functions are defined
 * they need to be globals as to be availabel to both autonomous and operator tasks
 **/

using namespace okapi;			// using okapi name space - pros specific calls/objects must be
 														// be proceeded by pros:: for example pros::Task::delay

// decalre the drive chasis controller -- make sure wheel diameter and chasis diameter or set
/*auto drive = ChassisControllerFactory::create(
    LEFT_DRIVE, -RIGHT_DRIVE,
    AbstractMotor::gearset::green,
    {4_in, 11.5_in}
);

// declare a lift controller
auto liftControl = AsyncControllerFactory::posIntegrated(
    {LIFT_MOTOR_ONE, LIFT_MOTOR_TWO, -LIFT_MOTOR_THREE}
);

// creat motor object to set motor parameters
MotorGroup liftGroup(
  {LIFT_MOTOR_ONE,LIFT_MOTOR_TWO, -LIFT_MOTOR_THREE}
);
*/
