#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include<d3d9.h>
#include"GraphicHandler.h"

class GameWindow
{
private:
	HWND g_hWnd;
	WNDCLASS wndClass;
	HINSTANCE hInstance;

	GraphicHandler* render;

public:
	GameWindow();
	WNDCLASS getWndClass();
	HWND getGHWnd();
	int createWindow();
	void removeWindow();
	bool loop();
};

