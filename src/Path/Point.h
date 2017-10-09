
#include <cmath>

#ifndef POINT_H
#define POINT_H

class Point
{
public:
	Point(int X, int Y);
	Point(Point point1, Point point2);

	void RotateBy(float Angle_Degrees);


	double Enclidean_Dist();
	static double Calc_Enclidean_Dist(Point &A, Point &B);
	static double Calc_Enclidean_Dist(Point &A);

	double X();
	double Y();
	void SetX(float X);
	void SetY(float Y);

private:
	double X_, Y_;
	double Enclidean_Dist_;
};

Point::Point(int X, int Y)
{
	X_ = X;
	Y_ = Y;

	Enclidean_Dist_ = std::sqrt(std::pow(X_, 2.0) + std::pow(Y_, 2.0));
}

void Point::RotateBy(float Angle)
{
	float temp = X_;
	X_ = X_ * std::cos(float(Angle / 180 * M_PI)) - Y_ * std::sin(float(Angle / 180 * M_PI));
	Y_ = Y_ * std::sin(float(Angle / 180 * M_PI)) + temp * std::cos(float(Angle / 180 * M_PI));
}



double Point::Enclidean_Dist()
{
	return Enclidean_Dist_;
}

double Point::Calc_Enclidean_Dist(Point &A, Point &B)
{
	return std::sqrt(std::pow(A.X() - B.X(), 2) + std::pow(A.Y() - B.Y(), 2));
}

double Point::Calc_Enclidean_Dist(Point &A)
{
	return std::sqrt(std::pow(A.X(), 2) + std::pow(A.Y(), 2));
}

double Point::X()
{
	return X_;
}

void Point::SetX(float X)
{
	X_ = X;
}

double Point::Y()
{
	return Y_;
}

void Point::SetY(float Y)
{
	Y_ = Y;
}

#endif
