#ifndef __SCENEMANAGER_H__
#define __SCENEMANAGER_H__
#include "Debug.h"
#include "Scene.h" 
#include "define.h" 

class SceneManager
{
private:
	static SceneManager * instance;
	Scene * scene;

public:
	SceneManager();
	~SceneManager();


	static SceneManager * GetInstance();

	void SetScene(Scene * x);

	void KeyState(BYTE *state);
	void OnKeyDown(int KeyCode);
	void OnKeyUp(int KeyCode);

	void LoadResources();
	void Update(DWORD dt);
	void Render();


	Scene * GetScene();

};

#endif 