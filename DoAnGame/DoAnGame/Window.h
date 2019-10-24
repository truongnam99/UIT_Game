#pragma once
#ifndef WINDOW_DEFINE
#define WINDOW_DEFINE

#include <windows.h>

#include "Define.h"
class Window
{
private:
	static Window *__instance;
	Window();
	HWND hWnd;

public:
	HINSTANCE hInstance;
	static Window * GetInstance();
	static LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void InitWindow();
	HWND GetHWnd();
	~Window();
};

#endif // Window_define
