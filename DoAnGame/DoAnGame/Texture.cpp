#include "Texture.h"
Texture * Texture::__instance = NULL;

Texture::Texture()
{
}


LPDIRECT3DTEXTURE9 Texture::GetTexture(int id)
{
	return textures[id];
}

void Texture::Add(int id, LPCWSTR path, D3DCOLOR transparentColor)
{
	D3DXIMAGE_INFO info;
	HRESULT hr = D3DXGetImageInfoFromFile(path, &info);
	if (hr != D3D_OK)
	{

		OutputDebugString(L"[ERROR] GetImageInfoFromFile failed: \n");
		return;
	}

	LPDIRECT3DDEVICE9 d3ddv = Game::GetInstance()->GetD3DDevice();
	LPDIRECT3DTEXTURE9 texture;

	hr = D3DXCreateTextureFromFileEx(d3ddv,
		path,
		info.Width,
		info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transparentColor,
		&info,
		NULL,
		&texture);
	if (hr != D3D_OK)
	{
		OutputDebugString(L"[ERROR] CreateTextureFromFile failed\n");
		return;
	}
	textures[id] = texture;

	OutputDebugString((wchar_t*)L"[INFO] Texture loaded Ok: id=,  \n");
}

Texture * Texture::GetInstance()
{
	if (__instance == NULL)
		__instance = new Texture();
	return __instance;
}

Texture::~Texture()
{
}
