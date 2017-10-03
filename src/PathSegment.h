
/*
 * Segment of path, arc or line
 */


//defining NULL, because eclipse...
#ifndef NULL
#define NULL   ((void *) 0)
#endif

#ifndef PATHSEGMENT_H
#define PATHSEGMENT_H

#define TO_END 0
#define TO_START 1
#define TO_CLOSEST_POINT 2

#define STRAIGHT_LINE 0
#define ARC 1

//0 so it does not affect the maths
#define NO_RADIUS 0

#include "Point.h"
#include "Math.h"
#include "PID.h"

class Path_Segment
{
public:
	Path_Segment(float MaxVelocity, Point Start, Point End, Point Center = NULL);
	Path_Segment(Point Start, Point End, float Radius);
	virtual ~Path_Segment();

	double Distance(Point From, int To);
	Point GetClosestPoint(Point From);

	float GetSteeringAngle(Point RobotPos);	//[-1 ... 0 ... 1]
	float GetForwardVal(Point RobotPos);

private:

	//0 if line, 1 if arc
	bool Segment_Type_;

	//Only for arc segments
	double Radius_;

	float MaxVel;

	Point Start_, End_, Center_;

	PID PID_Steering, PID_Forward;
};

#endif
