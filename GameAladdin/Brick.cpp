#include "Brick.h"



Brick::Brick()
{
	GameObject::GameObject();
	type = BRICK;
}

Brick::Brick(float x, float y, int width, int height, oType type)
{
	GameObject::GameObject();
	type = BRICK;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->type = type;
	nx = 0;
}


Brick::~Brick()
{
}

void Brick::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = (float)x;
	top = (float)y;
	right = left + (float)width;
	bottom = top + (float)height;
}
