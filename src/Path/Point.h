#ifndef POINT_H
#define POINT_H

#include <Math.h>

struct Point
{
	Point(int X, int Y);
	Point(Point point1, Point point2);

	int X_, Y_;
	double Enclidean_Dist;
};

Point::Point(int X, int Y)
{
	X_ = X;
	Y_ = Y;

	Enclidean_Dist = std::sqrt(float(std::pow(X_, 2.0) + std::pow(Y_, 2.0)));
}

#endif
