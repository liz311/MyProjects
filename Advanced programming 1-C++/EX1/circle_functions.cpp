/* Created By Lizzy Asis */

#include "Circle.h"
#include <cmath>

//defult construcktor
Circle::Circle(){}

//construcktor : seting values for center point , radius point and color
Circle::Circle(int x, int y, int r,int color):center(x,y) , radius(r) , color(color){}

//geting color from class
int Circle::getColor() const{return color;}

//seting value for color
void Circle::setColor(int color){this->color=color;}

//checking if the point contained in the cirlce
bool Circle::contains(const Point &p) const{
	int temp = p.getX() - center.getX();
	temp *= temp;
	int temp2 = p.getY() - center.getY();
	temp2 *= temp2;
	double dist = sqrt((double)(temp + temp2));
	return radius > dist;
	}

//display circle
void Circle::print() const
{
	std::cout << "Circle center = (" << center.getX() << "," << center.getY() << ")"
		<< " radius = " << radius << " color = " << color << endl;
}
