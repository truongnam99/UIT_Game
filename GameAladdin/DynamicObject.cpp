#include "DynamicObject.h"



void DynamicObject::Update(DWORD dt)
{
	animation->Update(dt);
	this->x += vx * dt*nx;
	this->y += vy * dt *ny;
}

void DynamicObject::SetVx(float vx)
{
	this->vx = vx;
}

void DynamicObject::SetVy(float vy)
{
	this->vy = vy;
}

void DynamicObject::SetVxy(float vx, float vy)
{
	this->vx = nx*vx;
	this->vy = ny*vy;
}

void DynamicObject::Render()
{
	int x = this->x - Camera::GetInstance()->GetXCam();
	int y = Map::GetInstance()->GetMapHeight() - (this->y + this->height) - Camera::GetInstance()->GetYCam();
	if (nx == -1)
		animation->Get()->DrawFlipX(x, y);
	else
		animation->Get()->Draw(x, y);
}

DynamicObject::DynamicObject()
{
}


DynamicObject::~DynamicObject()
{
}
