#include "Cell.h"





Cell::Cell(int id, int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->width = w;
	this->height = h;
}

bool Cell::isCheckContainPoint(Point a)
{
	if (a.x < x || a.x > x + width)
		return false;
	if (a.y < y || a.y > y + height)
		return false;
	return true;
}

Cell::~Cell()
{
	for (GameObject * o : object)
	{
		delete o;
	}
	object.clear();
}

void Cell::Move(float x, float y)
{
}
