//Chaz Del Prato
//CECS 282 Lab 6
#include "pointType.h"


void pointType::setPoint(double x, double y)
{
	xCoordinate = x;
	yCoordinate = y;
}

void pointType::print() const
{
	cout << "(" << xCoordinate << ", " << yCoordinate << ")" << endl;
}

double pointType::getX() const
{
	return xCoordinate;
}

double pointType::getY() const
{
	return yCoordinate;
}

pointType::pointType(double x, double y)
{
	xCoordinate = x;
	yCoordinate = y;
}
