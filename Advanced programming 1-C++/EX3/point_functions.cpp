/* Created By Lizzy Asis */

#include "Point.h"

Point::Point(int x,int y) {setX(x); setY(y);}
Point::Point(const Point &inPoint) {setX(inPoint.getX());setY(inPoint.getY());}
Point::~Point() {}
Point &Point::operator=(const Point &inPoint) {setX(inPoint.getX());setY(inPoint.getY());return *this;}
void Point::setX(int x) {this->x = x;}
void Point::setY(int y){this->y = y;}
int Point::getX() const {return x;}
int Point::getY() const {return y;}
