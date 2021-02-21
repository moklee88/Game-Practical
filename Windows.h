#ifndef WINDOWS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <d3d9.h>
#include "resource.h"

class LiauWindows
{
private:
	HWND g_hWnd;
	WNDCLASS wndClass;
	HINSTANCE hInstance;
	D3DPRESENT_PARAMETERS d3dPP;
	IDirect3DDevice9 * d3dDevice;

public:
	LiauWindows();
	void createWindows();
	void clearWindows();
	bool loop();
	bool directX();
	void fullscreen();
};

#endif