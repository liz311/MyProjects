/* Created By Lizzy Asis */

#include "point.h"

//defult construcktor
Point::Point() {}

//construcktor : seting values for x , y
Point::Point(int x, int y)
{
	setX(x);
	setY(y);
}

//geting x from class
int Point::getX() const{return x;}

//geting y from class
int Point::getY() const{return y;}

//seting values for x
void Point::setX(int x){this->x=x;}

//seting values for y
void Point::setY(int y){this->y=y;}

//display point
void Point::print()const { cout<<"(" << getX() << "," << getX() <<")" << endl;}
