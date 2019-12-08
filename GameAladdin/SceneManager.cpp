#include "SceneManager.h"

SceneManager * SceneManager::instance = NULL;


SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

SceneManager * SceneManager::GetInstance()
{
	if (instance == NULL)
		instance = new SceneManager();
	return instance;
}

void SceneManager::SetScene(Scene * x)
{
	Scene * scene_temp = scene;
	scene = x;
	delete scene_temp;
}



void SceneManager::KeyState(BYTE * state)
{
	scene->KeyState(state);
}

void SceneManager::OnKeyDown(int KeyCode)
{
	scene->OnKeyDown(KeyCode);
}

void SceneManager::OnKeyUp(int KeyCode)
{
	scene->OnKeyUp(KeyCode);
}

void SceneManager::LoadResources()
{
	scene->LoadResources();

}

void SceneManager::Update(DWORD dt)
{
	scene->Update(dt);
}

void SceneManager::Render()
{
	scene->Render();
	
}


Scene * SceneManager::GetScene()
{
	return scene;
}
