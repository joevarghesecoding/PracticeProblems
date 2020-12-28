#ifndef CartesianPoints_h
#define CartesianPoints_h

#include <iostream>

using namespace std;

class CartesianPoints
{
private:
	double x;
	double y;

public:
	CartesianPoints()
	{
		x = 0.0;
		y = 0.0;
	}
	CartesianPoints(double, double);
	double getPointX();
	double getPointY();
	void setPoint(double, double);
};

#endif

