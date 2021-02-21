#include "Windows.h"

bool isFullscreen = false;
bool isRMax = false;
bool isGMax = false;
bool isBMax = false;
int red, blue, green, speed = 0, mode = 1;

void SetRGB(WPARAM wParam);
void MaxZero(WPARAM wParam);
void MaxDecrease(WPARAM wParam);
void MaxStop(WPARAM wParam);
void RandomRGB(WPARAM wParam);

LiauWindows::LiauWindows()
{
	this->g_hWnd = NULL;
	this->hInstance = GetModuleHandle(NULL);
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == 27)
		{
			PostQuitMessage(0);
		}

		else if (wParam == 70)
		{
			printf("F ");
			isFullscreen = true;
		}

		else if (wParam == 'D')
		{
			printf("D ");
			red = 0;
			green = 0;
			blue = 0;
		}

		else if (wParam == 'I')
		{
			printf("I ");
			if (speed < 255)
			{
				speed++;
			}
		}

		else if (wParam == 'O')
		{
			printf("O ");
			if (speed > 0)
			{
				speed--;
			}
		}

		//Maximum become zero
		else if (wParam == '1')
		{
			printf("Maximum become zero\n");
			printf("1 ");
			mode = 1;
		}

		//Maximum become decrease
		else if (wParam == '2')
		{
			printf("Maximum become decrease\n");
			printf("2 ");
			mode = 2;
		}

		//Maximum/Minimum stop
		else if (wParam == '3')
		{
			printf("Maximum/Minimum stop\n");
			printf("3 ");
			mode = 3;
		}

		//Random color
		else if (wParam == '4')
		{
			printf("Random color\n");
			printf("4 ");
			mode = 4;
		}

		SetRGB(wParam);

		printf("wParam-%d speed-%d R-%d G-%d B-%d\n", wParam, speed, red, green, blue);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void LiauWindows::createWindows()
{
	ZeroMemory(&wndClass, sizeof(wndClass));

	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	//wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1));
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = WindowProcedure;
	wndClass.lpszClassName = "Windows";
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

	RegisterClass(&wndClass);

	g_hWnd = CreateWindowEx(0, wndClass.lpszClassName, "Windows", WS_OVERLAPPEDWINDOW, 0, 100, 400, 300, NULL, NULL, hInstance, NULL);
	ShowWindow(g_hWnd, 1);

}

void LiauWindows::clearWindows()
{
	d3dDevice->Release();

	d3dDevice = NULL;

	UnregisterClass(wndClass.lpszClassName, hInstance);
}

bool LiauWindows::loop()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT) break;

		TranslateMessage(&msg);

		DispatchMessage(&msg);

	}

	if (isFullscreen == true)
	{
		fullscreen();
		isFullscreen = false;
	}

	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(red, green, blue), 1.0f, 0);

	d3dDevice->BeginScene();

	d3dDevice->EndScene();

	d3dDevice->Present(NULL, NULL, NULL, NULL);

	return msg.message != WM_QUIT;
}

bool LiauWindows::directX()
{
	IDirect3D9 * direct3D9 = Direct3DCreate9(D3D_SDK_VERSION);

	d3dPP.Windowed = true;
	d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dPP.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dPP.BackBufferCount = 1;
	d3dPP.BackBufferWidth = 480;
	d3dPP.BackBufferHeight = 640;
	d3dPP.hDeviceWindow = g_hWnd;

	HRESULT hr = direct3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dPP, &d3dDevice);

	if (FAILED(hr))
	{
		return false;
	}

	return true;
}

void LiauWindows::fullscreen()
{
	if (d3dPP.Windowed == true)
	{
		d3dPP.Windowed = false;
		d3dPP.BackBufferWidth = 1920;
		d3dPP.BackBufferHeight = 1080;
	}

	else if (d3dPP.Windowed == false)
	{
		d3dPP.Windowed = true;
		d3dPP.BackBufferWidth = 480;
		d3dPP.BackBufferHeight = 640;
	}

	HRESULT hr = d3dDevice->Reset(&d3dPP);

	if (FAILED(hr))
	{
		PostQuitMessage(0);
	}
}

void SetRGB(WPARAM wParam)
{
	if (mode == 1)
	{
		MaxZero(wParam);
	}

	else if (mode == 2)
	{
		MaxDecrease(wParam);
	}

	else if (mode == 3)
	{
		MaxStop(wParam);
	}

	else if (mode == 4)
	{
		RandomRGB(wParam);
	}

	if (red > 255)
		red = 255;

	else if (red < 0)
		red = 0;

	if (green > 255)
		green = 255;

	else if (green < 0)
		green = 0;

	if (blue > 255)
		blue = 255;

	else if (blue < 0)
		blue = 0;
}

void MaxZero(WPARAM wParam)
{
	if (wParam == 'R')
	{
		printf("R ");
		red += speed;

		if (red < 0)
		{
			red = 255;
		}

		else if (red > 255)
		{
			red = 0;
		}
	}

	else if (wParam == 'G')
	{
		printf("G ");
		green+= speed;

		if (green < 0)
		{
			green = 255;
		}

		else if (green > 255)
		{
			green = 0;
		}
	}

	else if (wParam == 'B')
	{
		printf("B ");
		blue += speed;

		if (blue < 0)
		{
			blue = 255;
		}

		else if (blue > 255)
		{
			blue = 0;
		}
	}
}

void MaxDecrease(WPARAM wParam)
{
	if (wParam == 'R')
	{
		printf("R ");

		if (isRMax == false)
		{
			red += speed;

			if (red > 255)
			{
				isRMax = true;
			}
		}

		else
		{
			red -= speed;

			if (red < 0)
			{
				isRMax = false;
			}
		}
	}

	else if (wParam == 'G')
	{
		printf("G ");

		if (isGMax == false)
		{
			green += speed;

			if (green > 255)
			{
				isGMax = true;
			}
		}

		else
		{
			green -= speed;

			if (green < 0)
			{
				isGMax = false;
			}
		}
	}

	else if (wParam == 'B')
	{
		printf("B ");

		if (isBMax == false)
		{
			blue += speed;

			if (blue > 255)
			{
				isBMax = true;
			}
		}

		else
		{
			blue -= speed;

			if (blue < 0)
			{
				isBMax = false;
			}
		}
	}

}

void MaxStop(WPARAM wParam)
{
	//red++
	if (wParam == 'R')
	{
		printf("R ");

		if (red >= 255)
		{
			printf("red is Maximum\n");
		}

		else
		{
			red += speed;
		}
	}
	//red--
	else if (wParam == 'T')
	{
		printf("T ");

		if (red <= 0)
		{
			printf("red is Minimum\n");
		}

		else
		{
			red -= speed;
		}
	}

	//green++
	else if (wParam == 'G')
	{
		printf("G ");

		if (green >= 255)
		{
			printf("green is Maximum\n");
		}

		else
		{
			green += speed;
		}
	}

	//green--
	else if (wParam == 'H')
	{
		printf("H ");

		if (green <= 0)
		{
			printf("green is Minimum\n");
		}

		else
		{
			green -= speed;
		}
	}

	//blue++
	else if (wParam == 'B')
	{
		printf("B ");

		if (blue >= 255)
		{
			printf("blue is Maximum\n");
		}

		else
		{
			blue += speed;
		}
	}

	//blue--
	else if (wParam == 'N')
	{
		printf("N ");

		if (blue <= 0)
		{
			printf("blue is Minimum\n");
		}

		else
		{
			blue -= speed;
		}
	}

}

void RandomRGB(WPARAM wParam)
{
	if (wParam == 'R')
	{
		printf("R ");
		red = rand() % 256;
		green = rand() % 256;
		blue = rand() % 256;
	}
}