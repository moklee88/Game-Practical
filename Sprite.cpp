#include "Sprite.h"


Sprite::Sprite()
{
	this->texture = NULL;
	this->sprite = NULL;
	this->spriteRect = { 0,0,0,0 };
	this->hr = D3DXCreateSprite(GraphicHandler::getInstance()->getD3dDevice(), &sprite);
	this->hr = D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "01.bmp", &texture);
}


RECT Sprite::getPosition()
{
	return spriteRect;
}

void Sprite::setPosition()
{
	this->spriteRect.left = this->spriteRect.top = 0;
	this->spriteRect.right = this->spriteRect.bottom = 32;
}


void Sprite::drawSprite()
{
	//	Clear and begin scene

//	Specify alpha blend will ensure that the sprite will render the background with alpha.
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	//	Sprite rendering. Study the documentation.
	sprite->Draw(texture, NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	//sprite->Draw(texture, &spriteRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	//sprite->Draw(texture, &spriteRect, NULL, &D3DXVECTOR3(32, 32, 0), D3DCOLOR_XRGB(255, 255, 255));

	//	End sprite drawing
	sprite->End();

	//	End and present scene
}

void Sprite::release()
{
	sprite->Release();
	sprite = NULL;

	texture->Release();
	texture = NULL;
}