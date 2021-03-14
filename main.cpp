#define WIN32_LEAN_AND_MEAN
#include "GameWindow.h"
#include "Sprite.h"
#include <stdio.h>

//--------------------------------------------------------------------

int main() {
	GameWindow* window = GameWindow::getInstance();
	GraphicHandler* graphic = GraphicHandler::getInstance();

	Sprite dummy;

	window->createWindow();

	graphic->initialize();
	graphic->draw();

	while (window->loop())
	{
		printf("Finally succeed\n");

	}

	graphic->release();
	window->removeWindow();

	window->releaseInstance();
	graphic->releaseInstance();

	return 0;
}