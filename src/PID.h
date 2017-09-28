#ifndef PID_H
#define PID_H

struct PID
{
	PID(double P, double I, double D);
	PID(double P, double I, double D, double F);
	double P_, I_, D_, F_;
};

PID::PID(double P, double I, double D)
{
	P_ = P;
	I_ = I;
	D_ = D;
	F_ = 0;
}

PID::PID(double P, double I, double D)
{
	P_ = P;
	I_ = I;
	D_ = D;
	F_ = 0;
}

#endif
