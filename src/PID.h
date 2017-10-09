#ifndef PID_H
#define PID_H

struct PID
{
	PID(float P, float I, float D);
	PID(float P, float I, float D, float F);
	float P_, I_, D_, F_;
};

PID::PID(float P, float I, float D)
{
	P_ = P;
	I_ = I;
	D_ = D;
	F_ = 0;
}

PID::PID(float P, float I, float D, float F)
{
	P_ = P;
	I_ = I;
	D_ = D;
	F_ = F;
}

#endif
