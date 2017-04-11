#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in2,    LiftPot,        sensorPotentiometer)
#pragma config(Sensor, in3,    ClawPot,        sensorPotentiometer)
#pragma config(Sensor, in4,    RLine,          sensorLineFollower)
#pragma config(Sensor, in5,    LLine,          sensorLineFollower)
#pragma config(Sensor, in6,    Gyro,           sensorGyro)
#pragma config(Sensor, in7,    TipDetect,      sensorAccelerometer)
#pragma config(Sensor, dgtl1,  RBaseEnc,       sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  LBaseEnc,       sensorQuadEncoder)
#pragma config(Motor,  port2,           RFBase,        tmotorVex393_MC29, openLoop, reversed, driveRight, encoderPort, dgtl1)
#pragma config(Motor,  port3,           LFBase,        tmotorVex393_MC29, openLoop, driveLeft, encoderPort, dgtl3)
#pragma config(Motor,  port4,           LiftR12,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           LiftL12,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           RBBase,        tmotorVex393_MC29, openLoop, reversed, driveRight, encoderPort, None)
#pragma config(Motor,  port7,           LBBase,        tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port8,           LiftR3L3,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           Claw,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**************************
BUILD DATE: 	4/8/16
AUTHOR: 			JAIVEER SINGH
V5.3.2
**************************/

//VRC Specific pragmas below
#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)
#include "/includes/Vex_Competition_Includes-.h"
//VRC Specific pragmas above

#include "Joystick_Defs.h" 	//Define joystick buttons in more user-friendly terms
#include "Constants.h" 			//All constants used in the entire program
#include "TrueSpeed_Slew.h" //Advanced motor control for the robot
#include "Base.h"						//All base-control code
#include "Claw.h" 					//All claw-control code
#include "Lift.h" 					//All lift-control code
#include "LCD.h"						//All LCD code
#include "SFX.h"
//#include "Auton_Func.h"			//Autonomous function code
//#include "Auton_Routines.h" //Autonomous routines code

/*
Function that starts tasks that need to always be on.
Has no inputs or outputs.
*/
void startAlwaysTasks()
{
	startTask(LCD);
	startTask(baseSlewControl);	//Super priority to Slew control
	startTask(liftSlewControl);
	//startTask(liftPD);
	startTask(clawPD, 10);
}

void startDriverTasks()
{
	startTask(base);
	startTask(lift);
	startTask(intake);
	startTask(SFX);
}

void failsafeChecks()
{
	liftFailsafeCheck();
	clawFailsafeCheck();
}

//Ready for match after reconnect
void pre_auton()
{
	startAlwaysTasks();
	//By slaving motors together, they can never accidentally drive in opposite directions
	slaveMotor(RBBase, RFBase);
	slaveMotor(LBBase, LFBase);
	slaveMotor(LiftR3L3, LiftR12);
	slaveMotor(LiftL12, LiftR12);
	//Get claw PD running
	//presetClaw(BACK);
	//Ready to go
	failsafeChecks();
	if(!liftActivateFailsafe && !clawActivateFailsafe)
	{
		playSound(soundFastUpwardTones);
	}
}

bool auton_flag = false;

task autonomous()
{
	failsafeChecks();
	//LeftC3S2x();
	auton_flag = true;
}

task usercontrol()
{
	failsafeChecks();
	startAlwaysTasks();	//Just in case comp control has turned them off
	startDriverTasks();	//Activate everything for driver
	while(true)
	{
		playImmediateTone(500, 1);
		EndTimeSlice();
	}
}