/*
Problem 10 page 191
Jyothish Joe Varghese
Last edit : 9/15/2020

Write and test a LineSegment class, described by two CartesianPoint endpoints (see
Exercises 4 and 10). In addition to the usual operations (such as constructors, input, and
output), this class should provide operations to compute
a. The midpoint of the line segment joining two points
b. The equation of the perpendicular bisector of this line segment

Write and test a class for a Line, described by its slope and a point on the line, with functions
that
a. Find the point-slope equation of the line
b. Find the slope-intercept equation of the line


Write a program to read the point and slope information for two lines and to determine
whether they intersect or are parallel. If they intersect, find the point of intersection and
also determine whether they are perpendicular. Use the classes Cartes; anPo; nt from
Exercises 4 and 10 and L; ne from Problem 11 to represent points and lines, respectively.
*/

#include "LineSegment.h"
#include "Line.h"
#include <iomanip>

using namespace std;

int main()
{	
	CartesianPoints x(1, 2); 
	CartesianPoints y(4, 4);
	CartesianPoints c(-2, 2);
	CartesianPoints d(-4, 5);
	LineSegment a(x,y);
	CartesianPoints midpoint;
	LineSegment b;
	Line test1(x, y);
	Line test2(c, d);
	

	cout << "Midpoint of a is : ";
	midpoint = (a.midPoint());
	cout << "(" << midpoint.getPointX() << "," << midpoint.getPointY() << ")";
	cout << endl;

	a.bisector();
	cout << endl;
	//cout << "Line Segment of a is: ";
	//a.getLineSegment();

	//cout << "Midpoint of b is : ";
	//b.midPoint();
	//cout << endl;

	//cout << "Midpoint of b is : ";
	//b.getLineSegment();
	//cout << endl;

	cout << "Point slope equation of line is: ";
	test1.pointSlopeEquation();
	cout << endl;

	cout << "Slope-intercept equation of the line is: ";
	test1.slopeInterceptEquation();
	cout << endl;

	//check if lines are parallel, if they intercept and if they are perpendicular
	if (test1.giveSlope() == test2.giveSlope())
	{
		cout << "Lines are parallel!" << endl;
	}
	else
	{	
		cout << fixed << setprecision(2);
		double xVal, yVal;
		xVal = (test2.giveYInt() - test1.giveYInt()) / (test2.giveSlope() - test1.giveSlope());
		yVal = (test2.giveSlope() * xVal) + (test2.giveYInt());
		cout << "The lines intersect at (" << xVal << "," << yVal << ")" << endl;
		if ((test1.giveSlope() == (-1 * (1 / test2.giveSlope()))) || test2.giveSlope() == (-1 * (1 / test1.giveSlope())))
			cout << "The lines are perpendicular!" << endl;
		else
			cout << "The lines are not perpendicular!" << endl;
	}

	return 0;
}

