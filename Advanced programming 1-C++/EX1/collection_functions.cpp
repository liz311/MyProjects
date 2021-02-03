/* Created By Lizzy Asis */

#include"Collection.h"

//defult construcktor
Collection::Collection(){}

//construcktor : memory allocation for circle-array and seting values in each circle
Collection::Collection(int radius, int width, int height, int _color):
	count(width*height)
{
	int curr_height = 0,curr_width = 0;
	cir=new Circle*[count];
	for (int x = 0; x < count;)
	{
		for (int y = 0; y < width; y++)
		{
			cir[x++] = new Circle (curr_width, curr_height, radius, 0);
			curr_width += 2*radius;

		}
		curr_width = 0;
		curr_height += 2 * radius;
	}

}

//destrucktor
Collection::~Collection()
{
	for(int i=0 ; i<count ; i++)
		delete [] cir[i];
	delete [] cir;
}

//returns the Circle that containing the point
Circle & Collection:: getRectAt(const Point &p)
{
	for(int i=0 ; i<count ; i++)
		if((cir[i]->contains(p))==true)
			return *this->cir[i];
}

//display circle-array
void Collection::print() const
{
	for(int i=0 ; i<count ; i++)
		cir[i]->print();
}
	
