
#ifndef PATH_PATH_H
#define PATH_PATH_H

#include "PathSegment.h"

class Path
{
public:
	Path_Segment Get_ClosestPath_Segment(Point Pos);
	std::vector<Path_Segment> Path_;
};

#endif
