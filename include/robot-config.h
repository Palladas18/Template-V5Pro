#include "driveTrain.h"
#include "pid.h"

using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller control;
extern motor Clamp;
extern motor FrontLeft;
extern motor FrontRight;
extern motor BackLeft;
extern motor BackRight;
extern motor FBarR;
extern motor FBarL;
extern inertial IMU;

driveTrain drive = driveTrain(3.25, 11.5);
pidController autonlinear = pidController(0, 0.002, 0, 0.0001);
pidController autonrotation = pidController(0, 0.001, 0, 0.0001);



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );