/* Created By Lizzy Asis */

#include "Collection.h"

void main()
{
	Collection c(4, 3, 2, 0);
	cout << "-- before setColor(2) --" << endl;
	c.print();
	Point p(5,1);
	c.getRectAt(p).setColor(2);
	cout << "-- after setColor(2) --" << endl;
	c.print();
}
