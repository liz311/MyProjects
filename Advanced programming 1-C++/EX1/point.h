/* Created By Lizzy Asis */

#ifndef POINT_HEADER
#define POINT_HEADER
#include <iostream>
using namespace std;
#endif

class Point
{
public:
	Point();
	Point(int x, int y);
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
	void print() const;
private:
	int x, y;
};

