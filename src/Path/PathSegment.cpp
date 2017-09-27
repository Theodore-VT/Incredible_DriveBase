
#include "PathSegment.h"

Path_Segment::Path_Segment(Point Start, Point End, Point Center):
Start_(Start),
End_(End),
Center_(Center)
{
	if(Center == NULL)
	{
		Segment_Type_ = STRAIGHT_LINE;
		Radius_ = Point(Center_, Start_).Enclidean_Dist;
	}
	else
	{
		Segment_Type_ = ARC;
		Radius_ = NO_RADIUS;
	}
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
			return Point(From, this->GetClosestPoint(From).Enclidean_Dist());

		}
	}

	else
		return -1;	//Error
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

		return Start_.RotateBy(Angle);
	}
	else
		return NULL;
}

float Path_Segment::GetSteeringAngle(float RobotAngle)
{
	return 0;
}

float Path_Segment::GetLineSteeringAngle(float RobotAngle)
{
	//1. find angle of the line
	float DeltaX = Start_.X() - End_.X();
	float DeltaY = Start_.Y() - End_.Y();

	float LineAngle = std::atan2(DeltaY, DeltaX) * 180 / M_PI;

	DistAngles(RobotAngle, LineAngle)
}
