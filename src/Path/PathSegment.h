
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

class Path_Segment
{
public:
	Path_Segment(Point Start, Point End, Point Center = NULL);
	virtual ~Path_Segment();

	double Distance(Point From, int To);

private:

	//0 if line, 1 if arc
	bool Segment_Type_;

	//Only for arc segments
	double Radius_;

	Point Start_, End_, Center_;
};

#endif
