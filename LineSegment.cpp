#include "LineSegment.h"
#include "CartesianPoints.h"

LineSegment::LineSegment(CartesianPoints a, CartesianPoints b)
{
	this->a.setPoint(a.getPointX(), a.getPointY());
	this->b.setPoint(b.getPointX(), b.getPointY());
}

void LineSegment::setLineSegment(CartesianPoints a, CartesianPoints b)
{
	this->a.setPoint(a.getPointX(), a.getPointY());
	this->b.setPoint(b.getPointX(), b.getPointY());
}

void LineSegment::getLineSegment()
{
	cout << "A: (" << a.getPointX() << "," << a.getPointY() << ")" << endl;
	cout << "B: (" << b.getPointX() << "," << b.getPointY() << ")" << endl;
}

CartesianPoints LineSegment::midPoint()
{
	CartesianPoints midpoint;
	midpoint.setPoint(((this->a.getPointX() + this->b.getPointX()) / 2), ((this->a.getPointY() + this->b.getPointY()) / 2));
	/*cout << endl;
	cout << "point x = " << ((this->a.getPointX() + this->b.getPointX()) / 2) << " and point y = " << ((this->a.getPointY() + this->b.getPointY()) / 2) << endl;*/
	//cout << "(" << midpoint.getPointX() << "," << midpoint.getPointY() << ")" << endl;
	return midpoint;
}

void LineSegment::bisector()
{
	CartesianPoints midpoint = this->midPoint();
	double slope = (this->b.getPointY() - this->a.getPointY()) / (this->b.getPointX() - this->a.getPointX());
	double perpenSlope = -1 * (1 / slope);
	double yint = (midpoint.getPointY() - (perpenSlope * midpoint.getPointX()));

	cout << "Equation of the bisector is : " << "Y = " << perpenSlope << " * x + " << yint << endl;
}