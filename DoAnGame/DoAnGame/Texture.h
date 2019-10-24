#pragma once
#ifndef TEXTURE_DEFINE
#define TEXTURE_DEFINE

#include <unordered_map>
#include "Game.h"

using namespace std;

class Texture
{
private:
	static Texture *__instance;
	unordered_map<int, LPDIRECT3DTEXTURE9> textures;

	Texture();
public:
	LPDIRECT3DTEXTURE9 GetTexture(int id);
	void Add(int id, LPCWSTR path, D3DCOLOR transparentColor);

	static Texture * GetInstance();
	~Texture();
};

#endif // !TEXTURE_DEFINE


