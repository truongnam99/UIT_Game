#include "Window.h"

Window *Window::__instance = NULL;

Window::Window()
{
}

Window * Window::GetInstance()
{
	if (__instance == NULL)
		__instance = new Window();
	return __instance;
}

LRESULT CALLBACK Window::WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void Window::InitWindow()
{
	hInstance = GetModuleHandle(NULL);

	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	hWnd =
		CreateWindow(
			WINDOW_CLASS_NAME,
			WINDOW_TITLE,
			WS_OVERLAPPEDWINDOW, 
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			NULL,
			NULL,
			hInstance,
			NULL);
	if (!hWnd)
	{
		OutputDebugString(L"[ERROR] CreateWindow failed");
		DWORD ErrCode = GetLastError();
		return;
	}
	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);
}

HWND Window::GetHWnd()
{
	return hWnd;
}

Window::~Window()
{
}
