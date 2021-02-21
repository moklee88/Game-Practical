#pragma once
#include <d3d9.h>
#include "GameWindow.h"

class GraphicHandler
{
private:
	IDirect3D9* direct3D9;
	D3DPRESENT_PARAMETERS d3dPP;
	IDirect3DDevice9* d3dDevice;
	HRESULT hr;
	GameWindow* window;

public:
	GraphicHandler(WNDCLASS* wndClass);
	void initialize(HWND g_hWnd);
	void draw();
	void clear();
};

