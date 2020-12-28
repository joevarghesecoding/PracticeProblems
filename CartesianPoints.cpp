#include "CartesianPoints.h"

CartesianPoints::CartesianPoints(double x, double y)
{
	this->x = x;
	this->y = y;
}

double CartesianPoints::getPointX()
{
	return this->x;
}

double CartesianPoints::getPointY()
{
	return this->y;
}

void CartesianPoints::setPoint(double x, double y)
{
	this->x = x;
	this->y = y;
}