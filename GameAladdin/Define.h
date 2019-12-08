#ifndef _DEFINE_H__
#define _DEFINE_H__


#include <fstream> 
#include <string>
#include <stdio.h>
#include <Windows.h>  
#include <iostream>
#include <map>
#include <algorithm>
#include <d3dx9.h>
#include <stdlib.h>
#include <iomanip>
#include <d3d9.h>
#include <vector>
#include <iostream>

#define SCREEN_WIDTH 315
#define SCREEN_HEIGHT 254
#define CAM_WIDTH 310
#define CAM_HEIGHT 234
#define MAX_FRAME_RATE 60

#define ALADDIN_POS_DEFAULT_WIDTH 130
#define ALADDIN_POS_DEFAULT_HEIGHT 52

#define WINDOW_CLASS_NAME L"Aladdin"
#define MAIN_WINDOW_TITLE L"Aladdin"

#define D3DCOLOR_BACKGROUND D3DCOLOR_XRGB(0, 0, 0)

#define MAP1 101
#define MAP2 102
#define MAP1_SIZE_OF_WIDTH 2264
#define MAP1_SIZE_OF_HEIGHT 1136
#define MAP2_SIZE_OF_WIDTH 500
#define MAP2_SIZE_OF_HEIGT 500

#define ID_TEX_BBOX -100

#define GRID_CELL_WIDTH 568
#define GRID_CELL_HEIGHT 280
#define ID_TEX_ALADDIN 1021
#define ID_TEX_ENEMY 1022

//object type
enum oType
{
	ALADDIN = 0,
	BOB = 1,
	BAT = 2,
	APPLE = 3,
	WALL = 4,
	BRICK = 5,
	ROPE = 6, // dây thừng
	MOVINGBRICK = 7
};

struct Point 
{
	int x;
	int y;
};

struct BoundingBox
{
	float top, left, right, bottom;
	float vx, vy;

	BoundingBox(){}
	~BoundingBox(){}
};

#endif