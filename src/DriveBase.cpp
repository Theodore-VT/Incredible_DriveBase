#include <DriveBase.h>

DriveBase::DriveBase()
//DriveMotors{{MOTOR_FR_PORT}, {MOTOR_MR_PORT}, {MOTOR_BR_PORT}, {MOTOR_BL_PORT}, {MOTOR_ML_PORT}, {MOTOR_FL_PORT}},

{
	DriveMotorFR(4);
	DriveMotorFL(5);
	DriveMotorBR(6);
	DriveMotorBL(7);
	DriveMotorMR(8);
	DriveMotorML(9);
	/*
	DriveMotors[FR] = CANTalon(MOTOR_FR_PORT);
	DriveMotors[MR] = CANTalon(MOTOR_MR_PORT);
	DriveMotors[BR] = CANTalon(MOTOR_BR_PORT);
	DriveMotors[BL] = CANTalon(MOTOR_BL_PORT);
	DriveMotors[ML] = CANTalon(MOTOR_ML_PORT);
	DriveMotors[FL] = CANTalon(MOTOR_FL_PORT);
	 */
	Pos(0, 0);
	Velocity_ = 0;
	Speeds[0] = 0;
	Speeds[1] = 0;
	State_ = 0;
	WantedState_ = 0;

	Timer = 0;

	std::cout<<"Starting DriveBase at "<<Timer<<"\n";
}

DriveBase::~DriveBase()
{

}

void DriveBase::Drive(double X_Axis, double Y_Axis)
{
	if(X_Axis > 1)
		X_Axis = 1;
	else if(X_Axis < -1)
		X_Axis = -1;

	if(Y_Axis > 1)
		Y_Axis = 1;
	else if(Y_Axis < -1)
		Y_Axis = -1;

	Speeds[LEFT]  = Y_Axis + X_Axis;
	Speeds[RIGHT] = Y_Axis - X_Axis;
}

void DriveBase::Drive(Path path)
{
	float X = path.Get_ClosestPath_Segment(Pos).GetSteeringAngle(Pos);
	float Y = path.Get_ClosestPath_Segment(Pos).GetForwardVal(Pos);

	this->Drive(X, Y);
}

void DriveBase::Drive(Path path, double X_Axis, double Y_Axis)
{
	float X = path.Get_ClosestPath_Segment(Pos).GetSteeringAngle(Pos);
	float Y = path.Get_ClosestPath_Segment(Pos).GetForwardVal(Pos);

	X += X_Axis;
	Y += Y_Axis;

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
