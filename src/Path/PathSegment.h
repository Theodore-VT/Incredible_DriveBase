/*
 * A path segment is two WayPoints joined
 * by a straight line or an arc
 */

#ifndef PATHSEGMENT_H
#define PATHSEGMENT_H

#include <WayPoint.h>

class PathSegment
{
public:
	PathSegment(double timeStamp);
	virtual ~PathSegment();

	void Update(double timeStamp);

	void ExtrapolateMotioState(); //TODO

	void SetStart(WayPoint wantedStart);
	WayPoint GetStart();

	void SetEnd(WayPoint wantedEnd);
	WayPoint GetEnd();

private:

	double m_clock;

	WayPoint Start, End;
};

#endif
