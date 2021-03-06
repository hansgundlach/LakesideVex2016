#pragma config(Motor,  port1,           Cubeholder,    tmotorVex393, openLoop)
#pragma config(Motor,  port2,           FrontLeftDrive, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           FrontRightDrive, tmotorVex393, openLoop)
#pragma config(Motor,  port4,           RearLeftDrive, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           RearRightDrive, tmotorVex393, openLoop)
#pragma config(Motor,  port6,           LeftArmBottom, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           LeftArmTop,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           RightArmBottom, tmotorVex393, openLoop)
#pragma config(Motor,  port9,           RightArmTop,   tmotorVex393, openLoop)


//port 7 and 6
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#pragma config(Motor,  port1,           port1Motor,    tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*#pragma config(Motor,  port1,           Cubeholder,    tmotorVex393, openLoop)
#pragma config(Motor,  port2,           FrontLeftDrive, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           FrontRightDrive, tmotorVex393, openLoop)
#pragma config(Motor,  port4,           RearLeftDrive, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           RearRightDrive, tmotorVex393, openLoop)
#pragma config(Motor,  port6,           LeftArmBottom, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           LeftArmTop,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           RightArmBottom, tmotorVex393, openLoop)
#pragma config(Motor,  port9,           RightArmTop,   tmotorVex393, openLoop)*/
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)
//get hacked by rohit u scrub #420noscoped
//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//switch 5 and 2
void move_forward(int power,int time)
{
//I'm going to modify this  to make rear drives goin opposite direction for 3 and 4
//frontleftdrive
//rightdrive
//rightdrive
		motor[FrontLeftDrive] = power;//-
		motor[RearLeftDrive] = power;
		motor[FrontRightDrive] = -power;//-
		motor[RearRightDrive] = power;//-
		wait1Msec(time);
		motor[FrontLeftDrive] = 0;
		motor[RearLeftDrive] = 0;
		motor[FrontRightDrive] = 0;
		motor[RearRightDrive] = 0;

}

void turn(int power,int time, int direction)//-1 for left, 1 for right
{

		motor[FrontLeftDrive] = power*direction;
		motor[RearLeftDrive] = power*direction;
		motor[FrontRightDrive] = power*direction*-1;
		motor[RearRightDrive] = power*direction*-1;

		wait1Msec(time);
		motor[FrontLeftDrive] = 0;
		motor[RearLeftDrive] = 0;
		motor[FrontRightDrive] = 0;
		motor[RearRightDrive] = 0;

}

/*void liftarm(int power,int time){
	motor[LeftArmBottom] = power;
		motor[LeftArmTop] = power;
		motor[RightArmBottom] =power;
		motor[RightArmTop] = power;
	wait1Msec(time);

	motor[LeftArmBottom] = 0;
		motor[LeftArmTop] = 0;
		motor[RightArmBottom] = 0;
		motor[RightArmTop] = 0;




}*/

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................

	move_forward(80,500);

}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
	  // This is the main execution loop for the user control program. Each time through the loop
	  // your program should update motor + servo values based on feedback from the joysticks.

	  // .....................................................................................
	  // Insert user code here. This is where you use the joystick values to update your motors, etc.
	  // .....................................................................................



	int RightDrive, LeftDrive = 0;
	int Slowdriving = 0;

	int Channel3 = vexRT(Ch3);
	int Channel1 = vexRT(Ch1);


	//as channel 1 increases right drive will go faster
	//left drive will decrease
	RightDrive = Channel3 + Channel1;
	LeftDrive = Channel3 - Channel1;

/*
old code for turning
motor[FrontLeftDrive] = LeftDrive;
	motor[RearLeftDrive] = LeftDrive;
	motor[FrontRightDrive] = RightDrive;
	motor[RearRightDrive] = RightDrive;*/

	motor[FrontLeftDrive] = RightDrive;
	  motor[RearLeftDrive] = LeftDrive;
	motor[FrontRightDrive] = RightDrive;
	 motor[RearRightDrive] = leftDrive;



	/*  2motor[FrontLeftDrive] = RightDrive;
	 4 motor[RearLeftDrive] = LeftDrive;
	3motor[FrontRightDrive] = RightDrive;
	 5motor[RearRightDrive] = leftDrive;*/

	/*#pragma config(Motor,  port2,           FrontLeftDrive, tmotorVex393, openLoop, reversed) increase
#pragma config(Motor,  port3,           FrontRightDrive, tmotorVex393, openLoop) increase
#pragma config(Motor,  port4,           RearLeftDrive, tmotorVex393, openLoop, reversed)decrease
#pragma config(Motor,  port5,           RearRightDrive, tmotorVex393, openLoop) decrease */








	//this is the constantly running motor
	motor[LeftArmTop]= 126;
	motor[LeftArmBottom] = 126;
	//motor[RightArmTop] = 124;












	/*if (vexRT[Btn5U] == 1)
	{
		motor[LeftArmBottom] = 40;
		motor[LeftArmTop] = 40;
		motor[RightArmBottom] = 40;
		motor[RightArmTop] = 40;
	}
	else if (vexRT[Btn5D] == 1)
	{
		motor[LeftArmBottom] = -40;
		motor[LeftArmTop] = -40;
		motor[RightArmBottom] = -40;
		motor[RightArmTop] = -40;
	}
	else
	{
		motor[LeftArmBottom] = 0;
		motor[LeftArmTop] = 0;
		motor[RightArmBottom] = 0;
		motor[RightArmTop] = 0;
	}

	if (vexRT[Btn6U] == 1)
	{
		motor[Cubeholder] = 120;
	}
	else if (vexRT[Btn6D] == 1)
	{
		motor[Cubeholder] = -120;
	}
	else
	{
		motor[Cubeholder] = 0;
	}*/




	if(vexRT[Btn8D]==1)
		{
		//this will move the thing forward
    //liftarm(80,400);
		move_forward(80,500);
		//turn(80,600, -1);
	}
	if(vexRT[Btn6U] == 1){
		//sets two upward motors
	 // button 8 and 9 will move up at the same time

	motor[RightArmBottom] = 126;
	motor[RightArmTop] = 126;
	wait1Msec(40);
	motor[RightArmBottom] = 0;
	motor[RightArmTop] = 0;



}






	}








	//testing for autonmous
	//this is going to be our forward method


}
