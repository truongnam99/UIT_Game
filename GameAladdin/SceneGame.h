#ifndef __SCENEGAME_H__
#define __SCENEGAME_H__
#include "SceneManager.h"
#include "Scene.h"
#include "Map.h"
#include "Textures.h"
#include "Grid.h"
#include "Aladdin.h"


class SceneGame:public Scene
{
private: 
	Aladdin * aladdin;
	Map * map;
	Camera * camera;
	Grid * grid;	
	int idMap; // Level trong game, có 2 level tương ứng với 2 Map
	Textures * textures;
	int StateCurrent;

	bool isGameOver;
	DWORD EndTime;
	float remainTime;
	int count;

	vector<LPGAMEOBJECT> obj;
public:
	void KeyState(BYTE *state); // Bắt các sự kiện phím để xử lý
	void OnKeyDown(int KeyCode); // 
	void OnKeyUp(int KeyCode);

	void LoadResources();
	void Update(DWORD dt);
	void Render();

	SceneGame();
	~SceneGame();
};

#endif