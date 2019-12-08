#include "SceneGame.h"

void SceneGame::KeyState(BYTE * state)
{
	float vx;
	float vy;
	aladdin->GetSpeed(vx, vy);

	
	if (Game::GetInstance()->IsKeyDown(DIK_RIGHT) || Game::GetInstance()->IsKeyDown(DIK_LEFT))
	{
		if (Game::GetInstance()->IsKeyDown(DIK_RIGHT))
			aladdin->SetNx(1);
		else
			aladdin->SetNx(-1);
		aladdin->SetSpeed(ALADDIN_WARK_SPEED, vy);
		if (Game::GetInstance()->IsKeyDown(DIK_C))
		{
			aladdin->SetCurrentState(ALADDIN_JUMPING_FOWARD);
		}
		else if (Game::GetInstance()->IsKeyDown(DIK_X))
		{
			aladdin->SetCurrentState(ALADDIN_RUNING_ATTACKING);
		}
		else if (Game::GetInstance()->IsKeyDown(DIK_Z))
		{
			aladdin->SetCurrentState(ALADDIN_RUNNING_ATTACKING_BY_APPLE);
		}
		else
		{
			if (!aladdin->isAttacking && !aladdin->isJumping)
				aladdin->SetCurrentState(ALADDIN_RUNNING1);
		}
		
	}
	else // nếu không nhấn thì trở về các trạng thái cũ khi kết thúc trạng thái
	{
		aladdin->SetCurrentState(ALADDIN_IDLE1);
		aladdin->SetSpeed(0, vy);
	}
	
}

void SceneGame::OnKeyDown(int KeyCode)
{
	
}

void SceneGame::OnKeyUp(int KeyCode)
{
}

void SceneGame::LoadResources()
{
	textures->LoadResources();
	map->SetMap(MAP1);
	map->LoadMap();
	camera->SetMap(map->GetMapWidth(), map->GetMapHeight());
	camera->SetPosition(0.0f, 0.0f);
	grid = Grid::GetInstance();
	grid->LoadGrid(MAP1);
	
	aladdin = new Aladdin();
	aladdin->LoadResource();
}

void SceneGame::Update(DWORD dt)
{
	grid->Update(dt);
	grid->GetObjects(obj);
	for (auto x : obj)
	{
		x->Update(dt);
	}
	// update aladdin
	aladdin->Update(dt, &obj);
	float x;
	float y;
	aladdin->GetPosition(x, y);
	//DebugOut((wchar_t*)L"x=%f, y=%f\n", x, y);
	camera->SetPosition(x - 140, y - 140);
}

void SceneGame::Render()
{
	map->DrawMap();
	aladdin->Render();
	
	// vẽ object trong grid

	int oCount=0;
	for (int i = 0; i < grid->cellShowing.size(); i++)
	{
		int id = grid->cellShowing[i];
		int oC = grid->GetCell(id)->object.size();
		for (int j = 0; j < oC; j++)
		{
			grid->GetCell(id)->object[j]->RenderBoundingBox(); // Vẽ renderBouding để debug
		}
	}
}

SceneGame::SceneGame()
{
	textures = Textures::GetInstance();
	camera = Camera::GetInstance();
	map = Map::GetInstance();
	LoadResources();
}

SceneGame::~SceneGame()
{
	delete aladdin;
}