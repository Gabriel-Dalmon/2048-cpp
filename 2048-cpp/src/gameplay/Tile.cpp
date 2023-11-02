#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>
#include <unordered_map>
#include "../../include/gamelogic/Tile.h"
#include "../../include/engine/SDLRenderer.h"

std::unordered_map<int, SDL_Surface*> Tile::tilesSpritesMap {
	{2, IMG_Load("src/assets/tiles/tile_2.png")},
	{4, IMG_Load("src/assets/tiles/tile_4.png")},
	{8, IMG_Load("src/assets/tiles/tile_8.png")},
	{16, IMG_Load("src/assets/tiles/tile_16.png")},
	{32, IMG_Load("src/assets/tiles/tile_32.png")},
	{64, IMG_Load("src/assets/tiles/tile_64.png")},
	{128, IMG_Load("src/assets/tiles/tile_128.png")},
	{256, IMG_Load("src/assets/tiles/tile_256.png")},
	{512, IMG_Load("src/assets/tiles/tile_512.png")},
	{1024, IMG_Load("src/assets/tiles/tile_1024.png")},
	{2048, IMG_Load("src/assets/tiles/tile_2048.png")}
};


Tile::Tile() : GameObject() {
	this->value = 0;
	this->mergedAlready = false;
	this->rect = new SDL_Rect;
	this->rect->x = 0;
	this->rect->y = 0;
	this->rect->h = 80;
	this->rect->w = 80;
	this->destRect = new SDL_Rect;
	(this->destRect->x, this->destRect->y, this->destRect->h, this->destRect->w) = (this->rect->x, this->rect->y, this->rect->h, this->rect->w);
	this->renderPointer = &Tile::render_empty;
	this->renderArray[0] = &Tile::render_empty;
	this->renderArray[1] = &Tile::render_smth;
}

Tile::~Tile() {
	delete this->rect;
	delete this->destRect;
}


void Tile::render(SDLScreen* screen) {
	(this->*renderPointer)(screen);
}

void Tile::render_empty(SDLScreen* screen){}


void Tile::render_smth(SDLScreen* screen){
	animate();

	char numberstring[(((sizeof(this->value)) * CHAR_BIT) + 2) / 3 + 2];
	sprintf_s(numberstring, "%d", this->value);

	SDL_Color color = { 255, 255, 255, 0 };
	SDL_BlitSurface(this->tilesSpritesMap[this->value], NULL, screen->surface, this->rect);
}

void Tile::swap_render(int value) {//0 for render_empty and 1 for render_smth
	this->renderPointer = this->renderArray[value];
}

void Tile::animate() {
		/*float deltaX = this->destRect->x - this->rect->x;
		float deltaY = this->destRect->y - this->rect->y;
		this->rect->x += int(std::ceil(deltaX / (this->destRect->x - deltaX + 1)));
		this->rect->y += int(std::ceil(deltaY / (this->destRect->y - deltaY + 1)));
		std::cout << this->value << "||" << deltaX << "||" << int(std::ceil(deltaX / (this->destRect->x - deltaX + 1))) << std::endl;*/
		

	if (this->destRect->x > this->rect->x) {
		this->rect->x += 2;
	}
	else if (this->destRect->x < this->rect->x) {
		this->rect->x -= 2;
	};
	if (this->destRect->y > this->rect->y) {
		this->rect->y += 2;
	}
	else if (this->destRect->y < this->rect->y) {
		this->rect->y -= 2;
	};
}