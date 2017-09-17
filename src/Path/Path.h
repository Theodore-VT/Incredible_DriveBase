/*
 * A path is defined as a serie of path segment
 * wich are arc or line based on wayPoints
 */

#ifndef PATH_PATH_H
#define PATH_PATH_H

#include <Vector>
#include <PathSegment.h>

class Path
{
public:
	Path();
	virtual ~Path();
private:
	std::vector<PathSegment>;
};

#endif
