#include "Line.h"

Line::Line(CartesianPoints start, CartesianPoints finish)
{
	this->a = start;
	this->b = finish;
	slope = (b.getPointY() - a.getPointY()) / (b.getPointX() - a.getPointX());
	yInt = b.getPointY() / (b.getPointX() * slope);
}

// prints the point-slope equation of the line y2-y1= m(x2-x1)
void Line::pointSlopeEquation()
{
	cout << b.getPointY() << " - " << a.getPointY() << " = " << slope << "(" << b.getPointX() << " - " << a.getPointX() << ")" << endl;
}

//prints the yintercept equation of the line y = mx + b
void Line::slopeInterceptEquation()
{
	cout << "Y = " << slope << " * x + " << yInt << endl;
}

//returns slope of the two points
double Line::giveSlope()
{
	return this->slope;
}

//returns y intercept
double Line::giveYInt()
{
	return this->yInt;
}
