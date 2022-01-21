#include "vex.h"

class driveTrain{
  public:

    driveTrain(double wheelDiameter, double wheelToWheel):
      wheelCircumfrence(wheelDiameter * M_PI), wheelBaseCircumfrence(wheelToWheel * M_PI)
    {}

    driveTrain(double wheelDiameter, double wheelToWheel, double linScale, double rScale):
      wheelCircumfrence(wheelDiameter * M_PI), wheelBaseCircumfrence(wheelToWheel * M_PI), yScaleJoy(linScale), rScaleJoy(rScale)
    {}

    driveTrain(double wheelDiameter, double wheelToWheel, double xScale, double yScale, double rScale):
      wheelCircumfrence(wheelDiameter * M_PI), wheelBaseCircumfrence(wheelToWheel * M_PI), yScaleJoy(yScale), rScaleJoy(rScale)
    {}

    double root2 = sqrt(2);
    double DPS2RPM = 6; // change realative motor cartridge eg 2 for blue and 12 for red
    double degToRad = M_PI / 180;
    double wheelCircumfrence;
    double wheelBaseCircumfrence;
    double maxRPM = 200; // change realative motor cartridge eg 600 for blue and 100 for red

    double yScaleJoy;
    double rScaleJoy;

    double yVel;
    double rVel;
    double linearVel;
    double joyAngle;
    double robotAngle;
    double modAngle;

    double wheelFL;
    double wheelFR;
    double wheelBL;
    double wheelBR;

    void calculateWheelSpeeds(double y, double r,double maxRPM){

  		double yRPM = (y/(wheelCircumfrence)) * (900 / DPS2RPM);
  		double rRPM = r;

      if(rRPM > maxRPM) rRPM = getSign(rRPM) * maxRPM;
      if(rRPM > maxRPM) yRPM = getSign(yRPM) * maxRPM;
      wheelFL = yRPM + rRPM;
  		wheelFR = yRPM - rRPM;
  		wheelBL = yRPM  + rRPM;
  		wheelBR = yRPM  - rRPM;

    }
  private:
    double getSign(double input){
      if(input == 0) return 0;
      return abs(input)/input;
    }
    double abs(double input){
      if(input > 0) return input;
      return -input;
    }
};