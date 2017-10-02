/*
 * DriveBase.cpp
 *
 *  Created on: 29 sept. 2017
 *      Author: 16150007
 */

#include <DriveBase.h>

DriveBase::DriveBase(double TimeStamp)
{
	DriveMotors[FR](MOTOR_FR_PORT);
	DriveMotors[MR](MOTOR_MR_PORT);
	DriveMotors[BR](MOTOR_BR_PORT);
	DriveMotors[BL](MOTOR_BL_PORT);
	DriveMotors[ML](MOTOR_ML_PORT);
	DriveMotors[FL](MOTOR_FL_PORT);

	State_ = 0;
	WantedState_ = 0;

	Timer = TimeStamp;

	std::cout<<"Starting DriveBase at "<<Timer<<"\n";
}

DriveBase::~DriveBase()
{

}

void DriveBase::Drive(double X_Axis, double Y_Axis)
{
	Speeds[LEFT]  = Y_Axis + X_Axis;
	Speeds[RIGHT] = Y_Axis - X_Axis;
}

void DriveBase::Drive(Path path)
{
	float X = path.Get_ClosestPath_Segment(Pos).GetSteeringAngle(Pos);
	float Y = path.Get_ClosestPath_Segment(Pos).GetForwardVal(Pos);

	this->Drive(X, Y);
}

void DriveBase::SetWantedState(int WantedState)
{
	WantedState_ = WantedState;
}


void DriveBase::Update(double TimeStamp)
{
	Timer = TimeStamp;
}

