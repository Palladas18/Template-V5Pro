#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller control = controller(primary);
motor Clamp = motor(PORT12, ratio36_1, false);
motor FrontLeft = motor(PORT1, ratio18_1, true);
motor FrontRight = motor(PORT2, ratio18_1, false);
motor BackLeft = motor(PORT3, ratio18_1, true);
motor BackRight = motor(PORT4, ratio18_1, false);
motor FBarL = motor(PORT5, ratio18_1, true);
motor FBarR = motor(PORT6, ratio18_1, false);
inertial IMU = inertial(PORT7);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain gyro
  wait(200, msec);

  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}