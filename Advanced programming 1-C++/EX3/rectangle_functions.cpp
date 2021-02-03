/* Created By Lizzy Asis */

#include "Rectangle.h"

Rectangle::Rectangle():Polygon(1) {setCoordinates(Point(0,0),Point(0,0));}
Rectangle::Rectangle(Point topLeft,Point bottomRight):Polygon(4) 
{
	setCoordinates(topLeft,bottomRight);
	sideArray[0] = bottomRight.getX() - topLeft.getX();
	sideArray[1] = topLeft.getY() - bottomRight.getY();
	sideArray[2] = sideArray[0];
	sideArray[3] = sideArray[1];
}
Rectangle::~Rectangle() {}
void Rectangle::setCoordinates(Point topLeft,Point bottomRight) 
{
	this->topLeft = topLeft;
	this->bottomRight = bottomRight;
}
double Rectangle::getArea() const  {return (Polygon::sideArray[0])*(Polygon::sideArray[1]);}
