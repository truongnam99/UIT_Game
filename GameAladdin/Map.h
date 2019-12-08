#ifndef __MAP__
#define __MAP__
#include <d3dx9.h>
#include <d3d9.h>
#include "Textures.h"
#include "Define.h"
#include "Sprites.h"
#include "Camera.h"

// Lớp này tương đương background

class Map
{
private:
	static Map * instance;
	Sprite * sprite;

	int idMap;

	int ColumnTile, RowTile, TotalTiles;
	int ColumnMap, RowMap;

	int tileSize;

	int TileMap[500][500];

	Map();
public:
	void SetMap(int idMap) { this->idMap = idMap; }
	void LoadMap();
	void SetTileSize(int tileSize);
	void ReadMapTXT(char * fileName);
	void DrawMap();
	int GetMapWidth();
	int GetMapHeight();

	static Map * GetInstance();
	~Map();
};

#endif // !__MAP__
