#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include "Animations.h"
#include "Camera.h"
#include "Map.h"

using namespace std;

class GameObject;
typedef GameObject * LPGAMEOBJECT;

struct CollisionEvent;
typedef CollisionEvent * LPCOLLISIONEVENT;

struct CollisionEvent
{
	LPGAMEOBJECT obj;
	float t, nx, ny;
	CollisionEvent(float t, float nx, float ny, LPGAMEOBJECT obj = NULL) { this->t = t; this->nx = nx; this->ny = ny; this->obj = obj; }

	static bool compare(const LPCOLLISIONEVENT &a, LPCOLLISIONEVENT &b)
	{
		return a->t < b->t;
	}
};

class GameObject
{
protected:
	float x; // Tọa độ Object trên map
	float y;
	float dx; // Quảng đường dịch chuyển trong thời gian dt:
	float dy; // dx = vx*dt; dy = vy*dt;
	float vx; // Tốc độ dịch chuyển của object
	float vy;
	int width;
	int height;

	float nx, ny; // Hướng

	int currentState; // Trạng thái

	DWORD dt; // Thời gian dt

	int health;
	oType type;

	unordered_map<int, Animation*> animations;
	
public:
	void SetPosition(float x, float y) { this->x = x; this->y = y; }
	void SetSpeed(float vx, float vy) { this->vx = vx; this->vy = vy; }
	void GetPosition(float &x, float &y) { x = this->x; y = this->y; }
	void GetSpeed(float &vx, float &vy) { vx = this->vx; vy = this->vy; }
	void SetSize(int w, int h) { this->width = w; this->height = h; };
	void GetSize(int &width, int &height) { width = this->width; height = this->height; };
	int GetCurrentState() { return this->currentState; }
	oType GetType() { return type; }
	void SetNx(int nx) { this->nx = nx; }
	void RenderBoundingBox();

	LPCOLLISIONEVENT SweptAABBEx(LPGAMEOBJECT coO);
	void CalcPotentialCollisions(vector<LPGAMEOBJECT> *coObjects, vector<LPCOLLISIONEVENT> &coEvents);
	void FilterCollision(
		vector<LPCOLLISIONEVENT> &coEvents,
		vector<LPCOLLISIONEVENT> &coEventsResult,
		float &min_tx,
		float &min_ty,
		float &nx,
		float &ny);

	void AddAnimation(int aniId);

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom) {};
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render(int flip = 1);
	virtual void SetCurrentState(int currenState) { this->currentState = currenState; }

	GameObject();
	~GameObject();
};

typedef GameObject * LPGAMEOBJECT;
#endif