#ifndef Line_h
#define Line_h

#include "CartesianPoints.h"

class Line
{
private: 
	CartesianPoints a;
	CartesianPoints b;
	double slope;
	double yInt;

public:
	Line()
	{
		a.setPoint(0.0, 0.0);
		b.setPoint(0.0, 0.0);
		slope = 0.0;
		yInt = 0.0;
	}
	Line(CartesianPoints start, CartesianPoints finish);
	void pointSlopeEquation();
	void slopeInterceptEquation();
	double giveSlope();
	double giveYInt();
};

#endif
