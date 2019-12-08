#include "Map.h"

Map * Map::instance = NULL;

void Map::SetTileSize(int tileSize)
{
	this->tileSize = tileSize;
}

void Map::LoadMap()
{
	switch (idMap) {
	case MAP1:
		this->idMap = idMap;
		ReadMapTXT((char*)"Resources/map/map1.txt");
		sprite->SetTexture(Textures::GetInstance()->Get(MAP1));
		break;
	case MAP2:
		ReadMapTXT((char*)"Resources/map/map2.txt");
		sprite = Sprites::GetInstance()->Get(MAP1); 
		sprite->SetTexture(Textures::GetInstance()->Get(MAP2));
		break;
	default:
		break;
	}

}

void Map::ReadMapTXT(char * fileName)
{
	ifstream input(fileName, ios::in);
	input >> TotalTiles;
	input >> ColumnMap;
	input >> RowMap;

	for (int i = 0; i < RowMap; i++) {
		for (int j = 0; j < ColumnMap; j++)
			input >> TileMap[i][j];
	}

	input.close();
}

void Map::DrawMap()
{
	Camera * camera = Camera::GetInstance();
	int _xCam = (int)camera->GetXCam();
	int _yCam = (int)camera->GetYCam();
	//kiem tra, xu ly camera co vuot qua map 
	if (_xCam < 0)
	{
		_xCam = 0;
		camera->SetX((float)_xCam);
	}
	if (_yCam < 0)
	{
		_yCam = 0;
		camera->SetY((float)_yCam);
	}
	if (_xCam + camera->GetWidth() > GetMapWidth())
	{
		_xCam = GetMapWidth() - camera->GetWidth();
		camera->SetX((float)_xCam);
	}
	if (_yCam + camera->GetHeight() > GetMapHeight())
	{
		_yCam = GetMapHeight() - camera->GetHeight();
		camera->SetY((float)_yCam);
	}

	//toa do ve len man hinh
	int x = -_xCam % tileSize;
	int xTemp = x;
	int y = -_yCam % tileSize;

	int iTile = _yCam /tileSize;//xac dinh tile bat dau cua qua trinh ve
	int jTile = _xCam / tileSize;
	int jT = jTile;// set lai trong vong lap

	int nTile = camera->GetHeight()/tileSize + iTile;//xac dinh vi tri tile ket thuc ve
	int kTile = camera->GetWidth()/tileSize + jTile;

	//xac dinh tile trong file tile.png de ve
	int frame;
	int rTile;
	int cTile;
	for (; iTile < nTile; iTile++)
	{
		for (jTile = jT; jTile < kTile; jTile++)
		{
			frame = TileMap[iTile][jTile];
			rTile = frame / 50;
			cTile = frame % 50;
			sprite->SetSprite(cTile*tileSize, rTile*tileSize, cTile*tileSize + tileSize, rTile*tileSize + tileSize);
			sprite->Draw((float)x, (float)y, 255);
			x += tileSize;
		}
		x = xTemp;
		y += tileSize;
	}
}

Map * Map::GetInstance()
{
	if (instance == NULL)
		instance = new Map();
	return instance;
}

int Map::GetMapWidth()
{
	return tileSize*ColumnMap;
}

int Map::GetMapHeight()
{
	return tileSize*RowMap;
}

Map::Map()
{
	tileSize = 8;
	sprite = new Sprite();
}


Map::~Map()
{
	delete sprite;
	delete instance;
}
