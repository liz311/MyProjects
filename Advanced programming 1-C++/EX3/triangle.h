/* Created By Lizzy Asis */

#ifndef TRIANGLE_HEADER
#define TRIANGLE_HEADER
#include "Polygon.h"

class Triangle : public Polygon
{
private:
	Point Point1,Point2,Point3;
public:
	Triangle();
	Triangle(Point,Point,Point);
	virtual ~Triangle();
	void setCoordinates(Point,Point,Point);
	double getArea() const;
};
#endif
