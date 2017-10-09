
#ifndef DRIVEBASE_H
#define DRIVEBASE_H

#include <CANTalon.h>
#include <Solenoid.h>

#include "Config.h"
#include <iostream>
#include "Path/Path.h"
#include "Path/Point.h"

#define OPEN_LOOP 0     			// Open loop voltage control
#define CLOSED_LOOP 1   			// Closed loop PID control



class DriveBase
{
public:
	DriveBase();
	virtual ~DriveBase();

	void Drive(double X_Axis, double Y_Axis);
	void Drive(Path path);
	void Drive(Path path, double X_Axis, double Y_Axis);

	void TurnToHeading(double WantedAngle);
	void DriveStraightLine(double Dist);

	void SetWantedState(int WantedState);

	void Update(double TimeStamp);

	float Velocity();	//returns velocity in m / s

private:

	//CANTalon DriveMotors[6];

	CANTalon DriveMotorFR;
	CANTalon DriveMotorFL;
	CANTalon DriveMotorBR;
	CANTalon DriveMotorBL;
	CANTalon DriveMotorMR;
	CANTalon DriveMotorML;


	double Speeds[2];	//6 motors, 2 sides


	int State_, WantedState_;

	float Velocity_;

	double Timer;

	Point Pos;

	//MotionState MotionState; //TODO

};

#endif
