#pragma config(Sensor, dgtl1,  led1,           sensorDigitalIn)
#pragma config(Sensor, dgtl2,  led2,           sensorDigitalIn)
#pragma config(Sensor, dgtl3,  led3,           sensorDigitalIn)
#pragma config(Sensor, dgtl4,  led4,           sensorDigitalIn)
#pragma config(Motor,  port1,           rd,            tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           ld,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           Catapult,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           Catapult1,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
while (true)  // This means that the robot will run through code inside of parenthesis multiple times
{
	motor[ld] = (vexRT[Ch2] + vexRT[Ch1])/2; // (y + x)/2 -- assigns left drive to the joysticks
	motor[rd] = (vexRT[Ch2] - vexRT[Ch1])/2; // (y - x)/2 --  assigns right drive to the joysticks

	while (vexRT[Btn5D] == 1) // While the button 5D is held down the robot will execute code below
		{
			motor(Catapult) = 100; // swings catapult at full power
			motor(Catapult1) = 100; //  swings as well
		}
}

}
