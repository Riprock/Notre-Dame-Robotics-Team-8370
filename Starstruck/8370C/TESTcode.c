#pragma config(Sensor, dgtl1,  backSonar,      sensorSONAR_inch)
#pragma config(Sensor, dgtl9,  leftRight,      sensorQuadEncoder)
#pragma config(Sensor, dgtl11, forwardBack,    sensorQuadEncoder)
#pragma config(Motor,  port2,           frontm,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftm,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           backm,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightm,        tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
* Stops all robot movement.
*/
void stopm(){
	motor[rightm]=0;
	motor[leftm]=0;
	motor[frontm]=0;
	motor[backm]=0;
}
/*
* Moves the robot forward idistance number of inches.
*/
void forward(float idistance, float speed){
	SensorValue[forwardBack] = 0;
	while (SensorValue[forwardBack] < 360 * (idistance/17)){
			motor[leftm] = -speed;
			motor[rightm] = -speed;
	}
	stopm();
}
/*
* Moves the robot backward idistance number of inches.
*/
void backward(float idistance, float speed){
	SensorValue[forwardBack] = 0;
	while (SensorValue[forwardBack] > -360 * (idistance/17)){
			motor[leftm] = speed;
			motor[rightm] = speed;
	}
	stopm();
}

task main(){
	forward(24, 50);
  backward(5, 127);
  forward(2, 50);
  backward(5, 127);
  forward(60, 127);
}