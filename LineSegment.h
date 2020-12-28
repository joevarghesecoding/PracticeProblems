/*
Problem 10 page 191
Jyothish Joe Varghese
Last edit : 9/15/2020

Write and test a LineSegment class, described by two CartesianPoint endpoints (see
Exercises 4 and 10). In addition to the usual operations (such as constructors, input, and
output), this class should provide operations to compute
a. The midpoint of the line segment joining two points
b. The equation of the perpendicular bisector of this line segment
*/

#ifndef LineSegment_h
#define LineSegment_h

#include <iostream>
#include "CartesianPoints.h"

using namespace std;

class LineSegment
{
public:
	LineSegment()
	{
		a.setPoint(0, 0);
		b.setPoint(0, 0);
	}
	LineSegment(CartesianPoints a, CartesianPoints b);	
	void setLineSegment(CartesianPoints a, CartesianPoints b);
	void getLineSegment();
	
	CartesianPoints midPoint();
	void bisector();

private:
	CartesianPoints a;
	CartesianPoints b;
};

#endif 