#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "GraphicHandler.h"
#include<d3d9.h>

class GameWindow
{
private:
	static GameWindow* sInstance;
	

	HINSTANCE hInstance;

public:
	WNDCLASS wndClass;
	HWND g_hWnd;

	GameWindow();
	
	static GameWindow* getInstance();
	static void releaseInstance();

	int createWindow();
	void removeWindow();
	bool loop();
};

