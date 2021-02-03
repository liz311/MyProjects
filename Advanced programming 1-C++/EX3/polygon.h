/* Created By Lizzy Asis */

#ifndef POLYGON_HEADER
#define POLYGON_HEADER
#include "Shape.h"

class Polygon : public Shape
{
protected:
	double *sideArray;
	int arrayLength;
public:
	Polygon();
	Polygon(int);
	double calculateSize(Point p1,Point p2) const;
	double getPerim() const;
	virtual ~Polygon();
	void setArrayLength(int);
	int getArrayLength() const;
};
#endif
