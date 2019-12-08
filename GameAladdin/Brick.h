#ifndef __BRICK__
#define __BRICK__

#include "GameObject.h"

class Brick: public GameObject
{
public:
	Brick();
	Brick(float x, float y, int width, int height, oType type);
	~Brick();

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	//void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL) {};
	void Render() { RenderBoundingBox(); };
	//void SetState(int state) { this->state = state; };
};

#endif __BRICK__