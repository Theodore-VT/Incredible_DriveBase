
#include <Math.h>
#include <stdlib.h>

#ifndef POINT_H
#define POINT_H

class Point
{
public:
	Point(int X, int Y);
	Point(Point point1, Point point2);

	void RotateBy(float Angle_Degrees);


	float Enclidean_Dist();

	float X();
	float Y();
	void SetX(float X);
	void SetY(float Y);

private:
	int X_, Y_;
	float Enclidean_Dist_;
};

Point::Point(int X, int Y)
{
	X_ = X;
	Y_ = Y;

	Enclidean_Dist_ = std::sqrt(float(std::pow(X_, 2.0) + std::pow(Y_, 2.0)));
}

void Point::RotateBy(float Angle)
{
	float temp = X_;
	X_ = X_ * std::cos(float(Angle / 180 * M_PI)) - Y_ * std::sin(float(Angle / 180 * M_PI));
	Y_ = Y_ * std::sin(float(Angle / 180 * M_PI)) + temp * std::cos(float(Angle / 180 * M_PI));
}



float Point::Enclidean_Dist()
{
	return Enclidean_Dist_;
}

float Point::X()
{
	return X_;
}

void Point::SetX(float X)
{
	X_ = X;
}

float Point::Y()
{
	return Y_;
}

void Point::SetY(float Y)
{
	Y_ = Y;
}

#endif
