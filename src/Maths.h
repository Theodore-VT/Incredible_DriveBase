#ifndef MATH_H
#define MATH_H

float DistAngles(float Angle1, float Angle2)
{
	float Diff;

	Diff = std::fmod(Angle2 - Angle1, 360);
	if (Diff < 0 )
		return Diff + 360;

	if (Diff > 180)
		return Diff - 360;

	return Diff;
}

#endif
