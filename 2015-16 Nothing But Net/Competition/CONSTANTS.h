//This header file contains all of the constants referenced throughout the driver competition code.
//EDIT WITH CAUTION!

//General Constants:
const int LOOP_DELAY = 10; //How long between each refresh of the while loops governing robot code, used because we do not need 1000 refreshes per second

//Base Constants:
//None, all base calculations are made relative to user control

//Launcher Constants:
const int LAUNCHER_SLOW_SPEED = 80; //How fast the launcher is adjusted on Slow setting
const int LAUNCHER_HOLD = 15; //How fast to move backwards so as to hold the launcher from firing

//Intake Constants
const int BALL_SENSED_LAUNCHER = 2100;
const int BALL_SENSED_ELEVATOR = 2500;
const int BALL_SENSED_RAMP = 2200;

//Autoloader Constants
const int AUTOLOAD_FORWARD = 100;
const int AUTOLOAD_BACK = -65;

//Angle Constants
const int ANGLE_TOLERANCE = 10; //How close the sensor values for angle need to be to the desired angle to shoot
const int ANGLE_ADJUST_SPEED = 50; //How fast the angle is adjusted when manually controlled by driver
int ANGLE_LONG_RANGE = 1660; //The potentiometer setting for shooting long range (starting tiles)
int ANGLE_SHORT_RANGE = 1530; //The potentiometer setting for shooting close up (midfield ish)
const int ANGLE_MAX_VAL = -1090; //Maximum limit for launcher
const int ANGLE_MIN_VAL = -720; //Minimum limit for launcher
const int ANGLE_HOLD = 10;
