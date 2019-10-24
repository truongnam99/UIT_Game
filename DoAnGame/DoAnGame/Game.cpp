#include "Game.h"

Game * Game::__instance = NULL;

Game::Game()
{
}

void Game::InitDirectDevice()
{
	//GetInstance();
	d3d = Direct3DCreate9(D3D_SDK_VERSION);;						// Direct3D handle
	d3ddv = NULL;
	this->hWnd = Window::GetInstance()->GetHWnd();
	
	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;

	RECT r;
	GetClientRect(hWnd, &r);

	d3dpp.BackBufferHeight = r.bottom + 1;
	d3dpp.BackBufferWidth = r.right + 1;

	d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddv);

	if (d3ddv == NULL)
	{
		OutputDebugString(L"[ERROR] CreateDevice failed\n");
		return;
	}

	d3ddv->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer);

	// Initialize sprite helper from Direct3DX helper library
	D3DXCreateSprite(d3ddv, &spriteHandler);

	OutputDebugString(L"[INFO] InitGame done;\n");

	this->d3d = d3d;
	this->d3ddv = d3ddv;
}

void Game::Render()
{
	if (d3ddv->BeginScene())
	{
		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
		Draw();
		spriteHandler->End();
		d3ddv->EndScene();
	}
	d3ddv->Present(NULL, NULL, NULL, NULL);
}


void Game::Run()
{
	MSG msg;
	int done = 0;
	DWORD frameStart = GetTickCount();
	DWORD tickPerFrame = 1000 / MAX_FRAME_RATE;
	//LoadResource();
	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				done = 1;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		DWORD now = GetTickCount();

		DWORD dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;

			//game->ProcessKeyboard();

			//Update(dt);
			Render();
		}
		else
			Sleep(tickPerFrame - dt);
	}
}

void Game::Draw()
{
	LPDIRECT3DTEXTURE9 tex = Texture::GetInstance()->GetTexture(0);
	D3DXVECTOR3 p(2, 2, 0);
	RECT rect;
	rect.top = 1;
	rect.left = 1;
	rect.bottom = 100;
	rect.right = 100;
	spriteHandler->Draw(tex, NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
}

void Game::LoadResource(LPCWSTR path)
{
	Texture * texture = Texture::GetInstance();
	texture->Add(0, path, D3DCOLOR_XRGB(255, 0, 255));
}

LPDIRECT3DDEVICE9 Game::GetD3DDevice()
{
	return d3ddv;
}

LPDIRECT3DSURFACE9 Game::GetBackBuffer()
{
	return backBuffer;
}

LPD3DXSPRITE Game::GetSpriteHandler()
{
	return spriteHandler;
}

Game * Game::GetInstance()
{
	if (__instance == NULL)
		__instance = new Game();
	return __instance;
}

Game::~Game()
{
	delete __instance;
}