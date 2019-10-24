#pragma once
#ifndef GAME_DEFINE
#define GAME_DEFINE
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include "Texture.h"
#include "Window.h"

class Game
{
private:
	static Game *__instance;

	LPDIRECT3D9			d3d = NULL;
	LPDIRECT3DDEVICE9	d3ddv = NULL;
	LPDIRECT3DSURFACE9	backBuffer = NULL;
	LPD3DXSPRITE		spriteHandler = NULL;
	HWND hWnd;

	Game();
	
	void Render();

public:
	

	void Run();
	void Draw();
	void LoadResource(LPCWSTR path);
	void InitDirectDevice();
	LPDIRECT3DDEVICE9 GetD3DDevice();
	LPDIRECT3DSURFACE9 GetBackBuffer();
	LPD3DXSPRITE GetSpriteHandler();
	static Game* GetInstance();
	~Game();
};

#endif