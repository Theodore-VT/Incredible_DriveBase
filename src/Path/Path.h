/*
 * Path.h
 *
 *  Created on: 2 oct. 2017
 *      Author: 16150007
 */

#ifndef SRC_PATH_PATH_H_
#define SRC_PATH_PATH_H_

#include <PathSegment.h>

class Path
{
public:
	Path_Segment Get_ClosestPath_Segment(Point Pos);
	std::vector<Path_Segment> Path_;
};

#endif
