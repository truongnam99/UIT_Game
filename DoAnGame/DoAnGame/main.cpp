#include "Window.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Window::GetInstance()->InitWindow();
	Game::GetInstance()->InitDirectDevice();
	Game::GetInstance()->LoadResource(L"D:\\LEARNING\\THIRD YEAR\\Game\\scoreboard.png");
	Game::GetInstance()->Run();
}