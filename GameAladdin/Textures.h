#pragma once
#ifndef __TEXTURE__
#define __TEXTURE__
#include <unordered_map>
#include "SceneManager.h"
#include "Game.h"
using namespace std;

class Textures
{
private:

	static Textures * instance;
	unordered_map<int, LPDIRECT3DTEXTURE9> textures;

	Textures();
public:
	static Textures * GetInstance();
	void Add(int id, LPCWSTR filePath, D3DCOLOR transparentColor);
	void LoadResources();
	LPDIRECT3DTEXTURE9 Get(int id);
	~Textures();
};

#endif