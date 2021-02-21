//	Ask the compiler to include minimal header files for our program.
#define WIN32_LEAN_AND_MEAN
#include "GameWindow.h"
#include <stdio.h>

//--------------------------------------------------------------------

int main() {
	GameWindow* window = new GameWindow();

	window->createWindow();
	//	Define Direct3D 9.
	//IDirect3D9* direct3D9 = Direct3DCreate9(D3D_SDK_VERSION);

	while (window->loop())
	{
		printf("Finally succeed\n");

	}

	window->removeWindow();
	delete window;

	return 0;
}