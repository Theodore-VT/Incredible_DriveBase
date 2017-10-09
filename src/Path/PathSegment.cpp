
#include "PathSegment.h"

Path_Segment::Path_Segment(float MaxVelocity, Point Start, Point End, Point Center):
MaxVel(MaxVelocity),
Start_(Start),
End_(End),
Center_(Center),
PID_Steering(0.3, 0.0012, 0.0003),
PID_Forward(0.2, 0.004, 0.00004)

{
		Radius_ = Point(Center_, Start_).Enclidean_Dist();
		Segment_Type_ = ARC;
}

Path_Segment::Path_Segment(float MaxVelocity, Point Start, Point End):
MaxVel(MaxVelocity),
Start_(Start),
End_(End),
Center_(-1, -1),
PID_Steering(0.3, 0.012, 0.003),
PID_Forward(0.1, 0.0007, 0.00605)

{
	Segment_Type_ = STRAIGHT_LINE;
	Radius_ = NO_RADIUS;
}

Path_Segment::~Path_Segment()
{

}

double Path_Segment::Distance(Point From, int To)
{
	if(To == TO_END)
		return Point(From, End_).Enclidean_Dist();

	else if(To == TO_START)
		return Point(From, Start_).Enclidean_Dist();

	else if(To == TO_CLOSEST_POINT)
	{
		if(Segment_Type_ == STRAIGHT_LINE)
		{

			//distance point line : https://www.khanacademy.org/math/geometry-home/analytic-geometry-topic/distance-between-a-point-and-a-line/v/distance-between-a-point-and-a-line

			double	SlopeSegment, SegmentConst, SlopePerp;

			SlopePerp = - 1 / SlopeSegment;

			double YIntersect, XIntersect;

			YIntersect = From.Y() - (From.X() * SlopePerp);

			XIntersect = (SegmentConst - YIntersect) * (SlopeSegment * - SlopePerp);

			return Point(From, Point(XIntersect, YIntersect)).Enclidean_Dist();
		}

		else if(Segment_Type_ == ARC)
		{
			return Point(From, this->GetClosestPoint(From)).Enclidean_Dist();
		}
	}

	return -1.0;	//Error
}

Point Path_Segment::GetClosestPoint(Point From)
{
	if(Segment_Type_ == STRAIGHT_LINE)
	{
		double	SlopeSegment, SegmentConst, SlopePerp;

		SlopePerp = - 1 / SlopeSegment;

		double YIntersect, XIntersect;

		YIntersect = From.Y() - (From.X() * SlopePerp);

		XIntersect = (SegmentConst - YIntersect) * (SlopeSegment * - SlopePerp);

		return Point(XIntersect, YIntersect);
	}
	else if(Segment_Type_ == ARC)
	{
		//Angle between the center, the start and the given point
		float Angle = std::atan2(Start_.Y() - From.Y(), Start_.X() - From.X()) -
					  std::atan2(Center_.Y() - From.Y(), Center_.X() - From.X());

		Point TempPoint = Start_;
		TempPoint.RotateBy(Angle);
		return TempPoint;
	}
	else
		return Point(0, 0);
}

float Path_Segment::GetSteeringAngle(Point RobotPos)
{
	static float Error, PrevError, TotalError;
	//1. find of wich side of the line we are
	//Delta < 0 : one side; Delta > 0 : other side
	double Delta = (RobotPos.X() - Start_.X()) * (End_.Y() - Start_.Y()) -
				  (RobotPos.Y() - Start_.Y()) * (End_.X() - Start_.X());	//This methode is called theouter product


	//2. Set Error
	PrevError = Error;
	Error = this->Distance(RobotPos, TO_CLOSEST_POINT) * (Delta / std::abs(Delta));
	TotalError += Error;

	//3. Calculate PID control
	float Steer = (PID_Steering.P_ * Error) + (PID_Steering.I_ * TotalError) + (PID_Steering.D_ * (Error - PrevError));

	//4. Normalize output
	 if(Steer < -1)
		 Steer = -1;
	 if(Steer > 1)
		 Steer = 1;

	return Steer;
}

float Path_Segment::GetForwardVal(Point RobotPos)
{
	static float Error, PrevError, TotalError;

	//1. Set Error
	PrevError = Error;
	Error = this->Distance(this->GetClosestPoint(RobotPos), TO_END);
	if(PrevError < Error)
		Error = -Error;
	TotalError += Error;

	//3. Calculate PID control
	float Forward = (PID_Forward.P_ * Error) + (PID_Forward.I_ * TotalError) + (PID_Forward.D_ * (Error - PrevError));

	//4. Normalize output
	 if(Forward < -1)
		 Forward = -1;
	 if(Forward > 1)
		 Forward = 1;

	 Forward = MaxVel * Forward;

	return Forward;

}

