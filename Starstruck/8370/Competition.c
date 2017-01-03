#pragma config(Sensor, dgtl9,  ArmEncoder,     sensorQuadEncoder)
#pragma config(Sensor, dgtl11, ArmTouch2,      sensorTouch)
#pragma config(Sensor, dgtl12, ArmTouch1,      sensorTouch)
#pragma config(Sensor, dgtl1,  newcube,      sensorDigitalIn)
#pragma config(Sensor, dgtl2,  oldcube,     sensorDigitalIn)
#pragma config(Sensor, dgtl3,  skills,        sensorDigitalIn)
#pragma config(Motor,  port1,           backRight,     tmotorVex393_HBridge, openLoop, driveRight)
#pragma config(Motor,  port2,           frontRight,    tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port3,           frontLeft,     tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port5,           backLeft,      tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port6,           armRight,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armRight2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           armLeft,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           armLeft2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          middleLeft,    tmotorVex393_HBridge, openLoop, reversed)

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
void stop_all(int time){	// stops all
	motor[armLeft] = 0;
	motor[armLeft2] = 0;
	motor[armRight] = 0;
	motor[armRight2] = 0;
	motor[backRight]= 0;
	motor[backLeft]= 0;
	motor[frontRight]= 0;
	motor[frontLeft]= 0;
	motor[middleLeft] = 0;
	wait1Msec(time);
	}
void cube_shoot(){
	while(SensorValue[ArmTouch1] != 1){
		// arm portion
		motor[armLeft] = 127;
		motor[armLeft2] = 127;
		motor[armRight] = -127;
		motor[armRight2] = -127;
		// drive portion
		motor[backRight]=-127;
		motor[backLeft]=-127;
		motor[frontRight]=-127;
		motor[frontLeft]=-127;
	}

	}
void back_shoot(){	// drives back and shoots
	//drive
	motor[backRight]=-127;
	motor[backLeft]=-127;
	motor[frontRight]=-127;
	motor[frontLeft]=-127;
	wait1Msec(600);
	// start arm
	while(SensorValue[ArmTouch1] != 1){
		// arm portion
		motor[armLeft] = 127;
		motor[armLeft2] = 127;
		motor[armRight] = -127;
		motor[armRight2] = -127;
		// drive portion
		motor[backRight]=-127;
		motor[backLeft]=-127;
		motor[frontRight]=-127;
		motor[frontLeft]=-127;
		}
	}
void left_turn(int time){ // moves left laterally (red)
	motor[backRight]=127;
	motor[backLeft]=-127;
	motor[frontRight]=127;
	motor[frontLeft]=-127;
	wait1Msec(time);
	}
void right_turn(int time){ // moves right laterally (blue)
	motor[backRight]=-127;
	motor[backLeft]=127;
	motor[frontRight]=-127;
	motor[frontLeft]=127;
	wait1Msec(time);
	}
void arm_down(int deg){	// moves arm down
	while (SensorValue[ArmEncoder] > deg){
		motor[armLeft] = -127;
		motor[armLeft2] = -127; //L -70, R 50 cube1
		motor[armRight] = 127;
		motor[armRight2] = 127;
	}
	}
void pause(int time){	// delay at beginning
	motor[armLeft] = 0;
	motor[armLeft2] = 0;
	motor[armRight] = 0;
	motor[armRight2] = 0;
	motor[backRight]= 0;
	motor[backLeft]= 0;
	motor[frontRight]= 0;
	motor[frontLeft]= 0;
	wait1Msec(time);
	}

void drive_forward(int time){ // drives forward
		motor[backRight]=127;
		motor[backLeft]=127;
		motor[frontRight]=127;
		motor[frontLeft]=127;
		wait1Msec(time);
}
void drive_backward(int time){ // drives forward
		motor[backRight]=-127;
		motor[backLeft]=-127;
		motor[frontRight]=-127;
		motor[frontLeft]=-127;
		wait1Msec(time);
	}
void arm_up(int deg){	// moves arm down
	while (SensorValue[ArmEncoder] < deg){
		motor[armLeft] = 127;
		motor[armLeft2] = 127; //L -70, R 50 cube1
		motor[armRight] = -127;
		motor[armRight2] = -127;
	}
	}
void old_cube(){
					SensorValue[ArmEncoder] = 0;
					back_shoot();
					stop_all(400); //stop
					drive_forward(270); //foreward a little
					stop_all(100);
					left_turn(350); //laeral
					stop_all(200); //stop
					drive_forward(990); // 500 ms == 3 ft
					stop_all(200);
					right_turn(360);
					stop_all(200);
					drive_backward(200);
					stop_all(500); //
					arm_down(20);
					stop_all(500);
					drive_forward(1500);
					stop_all(500);
					drive_backward(500);
					stop_all(500);
					arm_down(3);
					stop_all(500);
					drive_forward(1800);
					stop_all(500);
					cube_shoot();
	}
void pro_skills(){
	SensorValue[ArmEncoder] = 0;
	int startReturn = 800;

	back_shoot();
	stop_all(200);
	drive_forward(startReturn);
	stop_all(400);
	arm_down(3);
	stop_all(2000);

	cube_shoot();
	stop_all(400);
	drive_forward(startReturn);
	stop_all(400);
	arm_down(3);
	stop_all(2000);

	cube_shoot();
	stop_all(400);
	drive_forward(startReturn);
	stop_all(400);
	arm_down(3);
	stop_all(1400);

	arm_up(20);
	back_shoot();
	stop_all(300);
	drive_forward(startReturn);
	stop_all(400);
	arm_down(3);
	stop_all(1400);

	arm_up(20);
	back_shoot();
	stop_all(300);
	drive_forward(startReturn);
	stop_all(400);
	arm_down(3);
	stop_all(1400);

	arm_up(20);
	back_shoot();
	stop_all(300);
	drive_forward(startReturn);
	stop_all(400);
	arm_down(3);
	stop_all(1400);



	}
void alliance(){
					SensorValue[ArmEncoder] = 0;
					back_shoot();
					//stop_all(200);
					//drive_forward(800); //foreward a little
					//stop_all(50);
					//right_turn(100);
					//arm_down(3);
					//stop_all(50);//prev 200
					//drive_forward(500); //comp:200
					//stop_all(50); //prev 500
					//right_turn(200);
					//drive_forward(600);
	}
void new_cube(){
					SensorValue[ArmEncoder] = 0;
					back_shoot();
					stop_all(200);
					drive_forward(270); //foreward a little
					stop_all(50);
					left_turn(420); //laeral
					stop_all(50);
					drive_forward(1100); // 500 ms == 3 ft
					stop_all(50);
					right_turn(360);
					stop_all(50);//prev 200
					drive_backward(200); //comp:200
					stop_all(50); //prev 500
					arm_down(10);
					stop_all(50); //prev 500
					drive_forward(1500); // comp:1500
					stop_all(50);//prev 500
					drive_backward(500); // comp:500
					stop_all(50);//prev 500
					arm_down(3);
					stop_all(50);//prev 500
					drive_forward(1800); // comp:1800
					stop_all(50);//prev 500
					cube_shoot();

					drive_forward(100);
					stop_all(50);
					arm_down(3);
					stop_all(50);
					drive_forward(1500); //comp: 1500
					stop_all(50);
					arm_up(50);
					stop_all(50);
					back_shoot();
	}

task autonomous()
{

			new_cube();



					// positioning, side of arm aligned with first tab crossing, midsection of wheel aligned with second crossing of tabs
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

// Lower to defend position
task defendPositionl() {
	while(SensorValue[ArmEncoder] > 90) {
		motor[armLeft] = -127;
		motor[armLeft2] = -127;
		motor[armRight] = 127;
		motor[armRight2] = 127;
	}
	if (SensorValue[ArmEncoder] < 90) {
		motor[armLeft] = 0;
		motor[armLeft2] = 0;
		motor[armRight] = 0;
		motor[armRight2] = 0;
		return;
	}
}
// Raise to defend position
task defendPositionr() {
	while(SensorValue[ArmEncoder] < 90) {
		motor[armLeft] = 127;
		motor[armLeft2] = 127;
		motor[armRight] = -127;
		motor[armRight2] = -127;
	}
	if (SensorValue[ArmEncoder] > 90) {
		motor[armLeft] = 0;
		motor[armLeft2] = 0;
		motor[armRight] = 0;
		motor[armRight2] = 0;
		return;
	}
}

task usercontrol()
{
  // User control code inside the loop

  while (true)
  {

	  	float SpeedDivisor = 1;
	  	float backLimit = SensorValue[ArmTouch1];
			float LeftDrive = vexRT[Ch3]/SpeedDivisor, RightDrive = vexRT[Ch2]/SpeedDivisor;

//drive
			motor[frontLeft] = LeftDrive;
	  	motor[backLeft] = LeftDrive;
	  	motor[frontRight] = RightDrive;
	  	motor[backRight] = RightDrive;
// arm code
		if(vexRT[Btn6U] == 1 && backLimit == 0 )	// if button 6U is pressed, arm goes up
			{
				motor[armLeft] = 127;
				motor[armLeft2] = 127;
				motor[armRight] = -127;
				motor[armRight2] = -127;
			}
	 	 else if(vexRT[Btn6D] == 1) // if button 6D is pressed, arm goes down
			{
				motor[armLeft] = -127;
				motor[armLeft2] = -127;
				motor[armRight] = 127;
				motor[armRight2] = 127;
			}
		else // stays at 0
			{
				motor[armLeft] = 0;
				motor[armLeft2] = 0;
				motor[armRight] = 0;
				motor[armRight2] = 0;
			}

			if(vexRT[Btn8D] == 1){
				stop_all(1000000000);
			}
			if(vexRT[Btn8U] == 1){
			pro_skills();
		//SensorValue[ArmEncoder] = 0;

				//back_shoot();
				//	stop_all(200);
				//	drive_forward(270); //foreward a little
				//	stop_all(50);
				//	left_turn(350); //laeral
				//	stop_all(50);
				//	drive_forward(990); // 500 ms == 3 ft
				//	stop_all(50);
				//	right_turn(360);
				//	stop_all(50);//prev 200
				//	drive_backward(200); //comp:200
				//	stop_all(50); //prev 500
				//	arm_down(20);
				//	stop_all(50); //prev 500
				//	drive_forward(1500); // comp:1500
				//	stop_all(50);//prev 500
				//	drive_backward(500); // comp:500
				//	stop_all(50);//prev 500
				//	arm_down(3);
				//	stop_all(50);//prev 500
				//	drive_forward(1500); // comp:1800
				//	stop_all(50);//prev 500
				//	cube_shoot();

				//	drive_forward(300);
				//	arm_down(3);
				//	drive_forward(1500); //comp: 1500
				//	arm_up(50);
				//	back_shoot();
			}

	}
    // DO NOT REMOVE BELOW WITHOUT ASKING ANISH.
    UserControlCodePlaceholderForTesting();
  }
