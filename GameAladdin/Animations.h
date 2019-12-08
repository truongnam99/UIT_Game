#ifndef __ANIMATIONS__
#define __ANIMATIONS__

#include "Sprites.h"

class AnimationFrame
{
	Sprite* sprite;
	DWORD time;

public:
	AnimationFrame(Sprite* sprite, int time) { this->sprite = sprite; this->time = time; }
	DWORD GetTime() { return time; }
	Sprite* GetSprite() { return sprite; }
};

typedef AnimationFrame *LPANIMATION_FRAME;

class Animation
{
	DWORD lastFrameTime;
	int defaultTime;
	int currentFrame;
	int frameLoop;
	vector<LPANIMATION_FRAME> frames;
public:
	Animation(int defaultTime, int frameLoop = -1) { this->defaultTime = defaultTime; lastFrameTime = -1; currentFrame = -1; this->frameLoop = frameLoop; }
	void Add(int spriteId, DWORD time = 0);
	void Render(float x, float y, int alpha = 255, int flip = 1);
	void SetDefaultTime(int defaultTime) { this->defaultTime = defaultTime; };
	void SetCurrentFrame(int frame) { currentFrame = frame; };
	int GetCurrentFrame() { return currentFrame; };
	int GetCountFrame() { return frames.size(); }; // Đếm số framé
	~Animation();
};

typedef Animation *LPANIMATION;

class Animations
{
	static Animations * __instance;

	unordered_map<int, LPANIMATION> animations;

public:
	void Add(int id, LPANIMATION ani);
	LPANIMATION Get(int id);

	static Animations * GetInstance();
	~Animations();
};


#endif // __ANIMATIONS__

