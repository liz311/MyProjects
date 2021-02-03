#ifndef CIRCLE_HEADER
#define CIRCLE_HEADER
#include "Shape.h"
/* Created By Lizzy Asis */


class Circle : public Shape
{
private:
	int Radius;
	Point Coordinates;
	const double Pi;
public:
	Circle();
	Circle(Point,int);
	virtual ~Circle();
	void setCoordinates(Point); 
	void setRadius(int);
	int getRadius();
	double getArea() const;
	double getPerim() const;
};
#endif
