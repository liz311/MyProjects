/* Created By Lizzy Asis */

#ifndef SHAPE_HEADER
#define SHAPE_HEADER
#include "Point.h"
#include <cmath>

class Shape
{
public:
	virtual double getArea() const=0;
	virtual double getPerim() const=0;
	virtual ~Shape() {}
};
#endif
