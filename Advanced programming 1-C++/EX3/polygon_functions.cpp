/* Created By Lizzy Asis */

#include "Polygon.h"

Polygon::Polygon() {sideArray = new double[1]; sideArray[0] = 0.0; setArrayLength(0);}

Polygon::Polygon(int arrayLength) {setArrayLength(arrayLength);sideArray = new double[arrayLength];}
Polygon::~Polygon() {delete [] sideArray;}

//Function which measures the distance between two points.
double Polygon::calculateSize(Point p1,Point p2) const
{
	double leftExpression = p1.getX() - p2.getX();
	double rightExpression = p1.getY() - p2.getY();
	double Length = sqrt(pow(leftExpression,2) + pow(rightExpression,2));
	return Length;
}

double Polygon::getPerim() const 
{
	double Sum = 0.0;
	for (int i=0;i<arrayLength;i++)
		Sum = Sum + sideArray[i];
	return Sum;
}
void Polygon::setArrayLength(int arrayLength) {this->arrayLength = arrayLength;}
int Polygon::getArrayLength() const {return arrayLength;}
