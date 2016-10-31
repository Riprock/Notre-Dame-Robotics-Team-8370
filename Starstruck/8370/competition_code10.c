#pragma config(Motor,  port1,           middleRight,   tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           frontRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           backRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           backLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           armRight,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armRight2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           armLeft,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           armLeft2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          middleLeft,    tmotorVex393_HBridge, openLoop)
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
	/*Begin Autnomous code*/
clearTimer(T1);
	//Left square
		// drive forward 1 sec
			while(time1[T1] < 1000)
			{

    				motor[frontLeft] = 127;
    				motor[backLeft] = 127;
    				motor[frontRight] = 127;
    				motor[backRight] = 127;

			}
		// Raise arm

			while(time1[T1] < 1000)
			{

				motor(armLeft) = 127;
				motor(armLeft2) = 127;
				motor(armRight) = 127;
				motor(armRight2) = 127;


			}

			while(time1[T1] < 2000)
			{

				motor(armLeft) = 63;
				motor(armLeft2) = 63;
				motor(armRight) = 63;
				motor(armRight2) = 63;


			}
		// drive right x sec


			while(time1[T1] < 2000)
			{

				motor(armLeft) = 63;
				motor(armLeft2) = 63;
				motor(armRight) = 63;
				motor(armRight2) = 63;


			}
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
   /* Begin Driver Control Code*/

    /*
    Drive- Arcade Drive
    */
    // forward drive
    motor[frontLeft] = vexRT[Ch2];
    motor[backLeft] = vexRT[Ch2];
    motor[frontRight] = vexRT[Ch2];
    motor[backRight] = vexRT[Ch2];

	//turning-- set to axis 1
    motor[backRight] = vexRT[Ch3];
    motor[backLeft] = vexRT[Ch3];// (y + x)
    motor[frontRight] = -vexRT[Ch3]; // (y - x)
    motor[frontLeft] = -vexRT[Ch3];
    // middle wheels- -- set motors to axis 3
    while (true)
    {
    	if(vexRT[Btn6U] == 1)	// if button 6U is pressed, arm goes down
			{
    	motor[middleLeft] = vexRT[Ch1];
    	motor[middleRight] = vexRT[Ch1];
			}
			else
			{
			motor[middleLeft] = 0;
    	motor[middleRight] = 0;
			}
		}
    /*// left side-- set motors to axis 3
    motor[frontLeft] = vexRT[Ch3];
    motor[backLeft] = vexRT[Ch3];
    // right side-- set motors to axis 2
	  motor[frontRight] = vexRT[Ch2];
    motor[backRight] = vexRT[Ch2];
    // middle wheels- -- set motors to axis 1
    motor[middleLeft] = vexRT[Ch1];
    motor[middleRight] = vexRT[Ch1];
    */

    /*
    ARM CODE BELOW
    */
    while (true)
		{
			/* Raise Arm*/
     if(vexRT[Btn6U] == 1)	// if button 6U is pressed, arm goes down
			{
				motor(armLeft) = 127;
				motor(armLeft2) = 127;
				motor(armRight) = 127;
				motor(armRight2) = 127;
			}
			/* Lower Arm*/
	 	 else if(vexRT[Btn6D] == 1) // if button 6D is pressed, arm goes down
			{
				motor(armLeft) = -127;
				motor(armLeft2) = -127;
				motor(armRight) = -127;
				motor(armRight2) = -127;
			}
			/* Hold arm in position*/
			else // if no button is pressed the motor values are 0 (idle)
			{
				motor(armLeft) = 0;
				motor(armLeft2) = 0;
				motor(armRight) = 0;
				motor(armRight2) = 0;
			}
		}
    // DO NOT REMOVE BELOW WITHOUT ASKING ANISH.
    UserControlCodePlaceholderForTesting();
  }
}