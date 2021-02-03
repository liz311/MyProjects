/* Created By Lizzy Asis */

#ifndef CIRCLE_HEADER
#define CIRCLE_HEADER
#include "Point.h"
#endif

class Circle
{
public:
	Circle();
	Circle(int x, int y, int r, int color);
	int getColor() const;
	void setColor(int color);
	bool contains(const Point &p) const;
	void print() const;
private:
	const Point center;
	int radius, color;
};

