/* Created By Lizzy Asis */

#ifndef COLLECTION_HEADER
#define COLLECTION_HEADER
#include "Circle.h"
#endif

class Collection
{
public:
	Collection();
	Collection(int radius, int width, int height, int color);
	~Collection();
	Circle& getRectAt(const Point &p);
	void print() const;
private:
	int count;
	Circle **cir;
};

