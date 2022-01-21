#include "vex.h"
#include "robot-config.h"

const double wheelCircumfrence = 10*3.25 * M_PI/6;


int selected = 0;
std::string autons[4] = {"Disabled", "Auton1", "Auton2", "Auton3"};
int size = 4;

void autonSelector(){
  control.Screen.clearScreen();
  task::sleep(100);
  while(true){
    control.Screen.clearScreen();
    task::sleep(100);
    control.Screen.newLine();
    control.Screen.print(autons[selected].c_str());
    task::sleep(100);
     if(control.ButtonRight.pressing()){
       selected = (selected + 1 + size) % size;
     }else if(control.ButtonLeft.pressing()){
       selected = (selected - 1 + size) % size;
     }else if(control.ButtonA.pressing()){
       task::sleep(100);
       if(control.ButtonA.pressing()){
         goto slctEnd;
       }
     }
   }
   slctEnd:
   control.rumble("..");
}

double getEncoders(){
  return (FrontLeft.value()+FrontRight.value())/2;
}


void runDriveValues(){
  FrontLeft.spin(forward, drive.wheelFL, rpm);
	FrontRight.spin(forward, drive.wheelFR, rpm);
  BackLeft.spin(forward, drive.wheelBL, rpm);
  BackRight.spin(forward, drive.wheelBR, rpm); 
 /* Just add more motors with same values as the back/front for the same side
  MidLeft.move_velocity(drive.wheelBL);
	MidRight.move_velocity(drive.wheelBR);*/
}

void stopDrive(){
  FrontLeft.stop();
  FrontRight.stop();
  BackLeft.stop();
  BackRight.stop();
}

// uses inertial based auto correcting
void driveForward(double inches, pidController controller, double angle, pidController rtController, double maxRPM = 600){
  controller.resetID();
  rtController.resetID();
  double initialY = ((double) getEncoders()) *( wheelCircumfrence/900);
  double targetY = ((double) getEncoders()) * (wheelCircumfrence/900) + inches;
  controller.tVal = targetY;
  controller.error = controller.tVal - initialY;
  rtController.tVal = angle;
  rtController.error = angle - IMU.angle();
  while(!controller.withinTarget()){
    rtController.update(IMU.angle());
    controller.update(((double)getEncoders()) * wheelCircumfrence/900);
    drive.calculateWheelSpeeds(controller.calculateOut(), rtController.calculateOut(),maxRPM);
    runDriveValues();
    task::sleep(10);
  }
  FrontLeft.stop();
  BackLeft.stop();
  FrontRight.stop();
  FrontLeft.stop();
}

//turning

void turnAngle(double angle, pidController rtController, double maxRPM= 600){
  IMU.resetRotation();
  stopDrive();
  rtController.resetID();
  rtController.tVal = angle;
  rtController.error = angle - IMU.angle();
  while(!rtController.withinTarget()){
    rtController.update(IMU.angle());
    drive.calculateWheelSpeeds(0, 3*rtController.calculateOut(), maxRPM);
    runDriveValues();
    task::sleep(10);
  }
  stopDrive();
}