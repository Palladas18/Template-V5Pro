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

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );