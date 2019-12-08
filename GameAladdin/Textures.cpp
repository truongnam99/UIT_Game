#include "Textures.h"

Textures * Textures::instance = NULL;

Textures::Textures()
{
	//LoadResources();
}

Textures * Textures::GetInstance()
{
	if (instance == NULL)
		instance = new Textures();
	return instance;
}

void Textures::Add(int id, LPCWSTR filePath, D3DCOLOR transparentColor)
{
	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(filePath, &info);
	if (result != D3D_OK)
	{
		DebugOut((wchar_t*)L"[ERROR] GetImageInfoFromFile failed: %s\n", filePath);
		return;
	}


	LPDIRECT3DTEXTURE9 texture;
	LPDIRECT3DDEVICE9 d3ddv = Game::GetInstance()->GetDirect3DDevice();
	result = D3DXCreateTextureFromFileEx(
		d3ddv,								// Pointer to Direct3D device object
		filePath,							// Path to the image to load
		info.Width,							// Texture width
		info.Height,						// Texture height
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transparentColor,
		&info,
		NULL,
		&texture);								// Created texture pointer

	if (result != D3D_OK)
	{
		OutputDebugString(L"[ERROR] CreateTextureFromFile failed\n");
		return;
	}

	textures[id] = texture;

	DebugOut((wchar_t*)L"[INFO] Texture loaded Ok: id=%d, %s \n", id, filePath);
}

//load all texture in here
void Textures::LoadResources()
{
	//LOAD MAP
	Add(MAP1, (wchar_t*)L"Resources\\map\\map1.png", D3DCOLOR_XRGB(255, 255, 255));
	
	//ALADDIN
	Add(ID_TEX_ALADDIN, (wchar_t*)L"Resources\\textures\\aladdinfull.png", D3DCOLOR_XRGB(106, 148, 189));
	//ENEMY
	Add(ID_TEX_ENEMY, (wchar_t*)L"Resources\\textures\\enemy.png", D3DCOLOR_XRGB(120, 193, 152));
	Add(ID_TEX_BBOX, (wchar_t*)L"Resources\\textures\\bbox.png", D3DCOLOR_XRGB(255, 255, 255));
}

LPDIRECT3DTEXTURE9 Textures::Get(int id)
{
	return textures[id];
}


Textures::~Textures()
{
	if (instance != NULL)
		delete instance;
}
