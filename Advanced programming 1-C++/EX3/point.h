/* Created By Lizzy Asis */

#ifndef POINT_HEADER
#define POINT_HEADER
#include <iostream>
using namespace std;

class Point
{
private:
	int x,y;
public:
	Point(int=0,int=0);
	Point(const Point &);
	virtual ~Point();
	Point &operator=(const Point &);
	void setX(int);
	void setY(int);
	int getX() const;
	int getY() const;
};
#endif
