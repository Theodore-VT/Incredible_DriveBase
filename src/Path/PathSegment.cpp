
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
		return Point(From, End_).Enclidean_Dist;
	else if(To == TO_START)
		return Point(From, Start_).Enclidean_Dist;
	else if(To == TO_CLOSEST_POINT)
		return Point(From, Center_).Enclidean_Dist - Radius_;
	else
		return -1;	//Error
}

