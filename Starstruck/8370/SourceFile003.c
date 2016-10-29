#pragma config(Motor,  port1,           backRight,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           frontRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           backLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           armRight,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armRight2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           armLeft,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           armLeft2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          middleLeft,    tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR Team 8370   				 */
/*                                                                           */
/*        Autnonomous code: begins on line 71                                */
/*        Driver code: begins on line 95                                     */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{

				motor(armLeft) = 127;
				motor(armLeft2) = 127;
				motor(armRight) = -127;
				motor(armRight2) = -127;
				wait1Msec(900);
		// lower arm


	//Right square
		// drive forward 1 sec
		// Raise arm
		// drive left x sec
		// lower arm
  	//

	// DO NOT REMOVE BELOW WITHOUT ASKING ANISH.
  AutonomousCodePlaceholderForTesting();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  // User control code inside the loop

  while (true)
  {

    	motor[frontLeft] = vexRT[Ch3];
    	motor[backLeft] = vexRT[Ch3];
    	motor[frontRight] = vexRT[Ch2];
    	motor[backRight] = vexRT[Ch2];

    	if(vexRT[Btn5U] == 1)	// if button 6U is pressed, arm goes down
			{ motor[middleLeft] = vexRT[Ch1];}
			else
			{motor[middleLeft] = 0;}

			/* Raise Arm*/
    if(vexRT[Btn7U] == 1)	// if button 6U is pressed, arm goes down
			{
				motor[armLeft] = 127;
				motor[armLeft2] = 127;
				motor[armRight] = -127;
				motor[armRight2] = -127;
				wait1Msec(900);
			}
		if(vexRT[Btn6U] == 1)	// if button 6U is pressed, arm goes down
			{
				motor[armLeft] = 127;
				motor[armLeft2] = 127;
				motor[armRight] = -127;
				motor[armRight2] = -127;
			}
			/* Lower Arm*/
	 	 else if(vexRT[Btn6D] == 1) // if button 6D is pressed, arm goes down
			{
				motor[armLeft] = -127;
				motor[armLeft2] = -127;
				motor[armRight] = 127;
				motor[armRight2] = 127;
			}
			/* Hold arm in position*/
			else // if no button is pressed the motor values are 0 (idle)
			{
				motor[armLeft] = 0;
				motor[armLeft2] = 0;
				motor[armRight] = 0;
				motor[armRight2] = 0;
			}
	}
    // DO NOT REMOVE BELOW WITHOUT ASKING ANISH.
    UserControlCodePlaceholderForTesting();
  }
