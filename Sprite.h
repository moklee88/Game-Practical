#include <d3dx9.h>
#include "GraphicHandler.h"
class Sprite
{
private:
	LPDIRECT3DTEXTURE9 texture;
	LPD3DXSPRITE sprite;
	HRESULT hr;

	RECT spriteRect;

public:
	Sprite();

	RECT getPosition();
	void setPosition();

	void initialize();
	void drawSprite();
	void clear();

};
