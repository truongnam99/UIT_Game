#ifndef _ALADDIN_
#define _ALADDIN_
#include "GameObject.h"

#define ALADDIN_WARK_SPEED 0.12f
#define ALADDIN_GRAVITY 0.0015f
#define ALADIN_JUMP_SPEED 0.6f
#define ALADIN_STOP_SPEED 0.03f

#define ALADDIN_IDLE1 1 // nhìn qua lại
#define ALADDIN_IDLE2 2 // ném táo 1
#define ALADDIN_IDLE3 3 // ném táo 2
#define ALADDIN_IDLE_LOOK_UP 4 // nhìn lên
//#define ALADDIN_IDLE_LOOK_DOWN 6 // nhìn xuống
#define ALADDIN_IDLE_SIT 5 // ngồi xuống

#define ALADDIN_RUNNING1 6 // Chạy
#define ALADDIN_RUNNING2 7 // Chạy -> dừng lại

#define ALADDIN_PUSHING 8

#define ALADDIN_JUMPING 9
#define ALADDIN_JUMPING_FOWARD 10
// #define ALADDIN_FALLING 13

#define ALADDIN_STAYING_ATTACKING 11
#define ALADDIN_SITTING_ATTACKING 12
#define ALADDIN_STAYING_COMBO_ATTACKING 13
#define ALADDIN_RUNING_ATTACKING 14
#define ALADDIN_JUMPING_ATTACKING 15

#define ALADDIN_STAYING_ATTACKING_BY_APPLE 16
#define ALADDIN_SITTING_ATACKING_BY_APPLE 17
#define ALADDIN_RUNNING_ATTACKING_BY_APPLE 18
#define ALADDIN_JUMPING_ATTACKING_BY_APPLE 19

#define ALADDIN_CLIMBING 20
#define ALADDIN_FALLING 21 // nhảy ra khỏi dây

#define ALADDIN_DAMAGE 22
#define ALADDIN_DEATH 23
#define ALADDIN_VICTORY 24

#define ALADDIN_GROUP_STATE_IDLE 100
#define ALADDIN_GROUP_STATE_ATTACKING 101
#define ALADDIN_GROUP_STATE_JUMPPING 102
#define ALADDIN_GROUP_STATE_RUNNING 103
#define ALADDIN_GROUP_STATE_CLIMBING 104
#define ALADDIN_GROUP_STATE_END 105 // Trạng thái không bị tấn công


#include "Brick.h"
class Aladdin: public GameObject
{
private:
	bool isCollisWithBrick;
	int ny;
	DWORD time; // Thời gian để xét các state

	
	//int groupState; // Nhóm state: là nhóm những state để xét chuyển trạng thái
public:
	bool isAttacking, isJumping, isClimbing, isIdle, isRunning, isInjured; 
	Aladdin();
	~Aladdin();
	DWORD GetTime() { return time; }
	void SetTime(DWORD time) { this->time = time; }

	void LoadResource();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void Render(int flip = 1);
	void SetCurrentState(int currentState);

	void CollisionWithBrick(vector<LPGAMEOBJECT>* coObject);
	int GetGroupState(int state);
	int GetCurrentGroupState();
};

#endif // !_ALADDIN
