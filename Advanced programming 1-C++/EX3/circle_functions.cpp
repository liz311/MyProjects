/* Created By Lizzy Asis */

#include "Circle.h"

Circle::Circle():Pi(3.141592) {setCoordinates(Point(0,0));setRadius(0);}
Circle::Circle(Point Coordinates,int Radius):Pi(3.141592) {setCoordinates(Coordinates);setRadius(Radius);}
Circle::~Circle() {}
void Circle::setCoordinates(Point Coordinates) {this->Coordinates = Coordinates;}
void Circle::setRadius(int Radius) {this->Radius = Radius;}
int Circle::getRadius() {return Radius;}
double Circle::getArea() const{return Pi * Radius * Radius;}
double Circle::getPerim() const{return 2 * Pi * Radius;}
