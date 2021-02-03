/* Created By Lizzy Asis */

#ifndef RECTANGLE_HEADER
#define RECTANGLE_HEADER
#include "Polygon.h"

class Rectangle : public Polygon
{
private:
	Point topLeft, bottomRight;
public:
	Rectangle();
	Rectangle(Point,Point);
	virtual ~Rectangle();
	void setCoordinates(Point,Point);
	double getArea() const;
};
#endif
