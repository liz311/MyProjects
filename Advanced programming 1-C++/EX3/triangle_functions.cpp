/* Created By Lizzy Asis */

#include "Triangle.h"

Triangle::Triangle():Polygon(1) {setCoordinates(Point(0,0),Point(0,0),Point(0,0));}
Triangle::Triangle(Point Point1,Point Point2,Point Point3):Polygon(3) 
{
	setCoordinates(Point1,Point2,Point3);
	sideArray[0] = calculateSize(Point1,Point2);
	sideArray[1] = calculateSize(Point2,Point3);
	sideArray[2] = calculateSize(Point3,Point1);
}

Triangle::~Triangle() {}
void Triangle::setCoordinates(Point Point1,Point Point2,Point Point3)
{
	this->Point1 = Point1;
	this->Point2 = Point2;
	this->Point3 = Point3;
}
double Triangle::getArea() const
{
	double Side1, Side2, Side3, toReturn;
	Side1 = Polygon::sideArray[0];
	Side2 = Polygon::sideArray[1];
	Side3 = Polygon::sideArray[2];
	toReturn = (Side1+Side2+Side3)*(Side1+Side2-Side3)*(Side1-Side2+Side3)*(-Side1+Side2+Side3);
	return 0.25 * sqrt(toReturn);
}
