#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>

#include "../../include/gamelogic/Tile.h"
#include "../../include/engine/SDLRenderer.h"


Tile::Tile() : GameObject() {
	this->value = 0;
	this->mergedAlready = false;
	this->sprite = IMG_Load("src/assets/tile.png");
	this->rect = new SDL_Rect;
	this->rect->x = 0;
	this->rect->y = 0;
	this->rect->h = 40;
	this->rect->w = 40;
	this->font = TTF_OpenFont("src/assets/fonts/ttf-bitstream-vera-1.10/Vera.ttf", 16);
}

Tile::~Tile() {}


void Tile::render(SDLScreen* screen) {
	char numberstring[(((sizeof(this->value)) * CHAR_BIT) + 2) / 3 + 2];
	sprintf_s(numberstring, "%d", this->value);
	
	SDL_Color color = {255, 255, 255, 0};
	SDL_Surface* message = TTF_RenderText_Blended(this->font, numberstring, color);
	SDL_BlitSurface(this->sprite, NULL, screen->surface, this->rect);
	SDL_BlitSurface(message, NULL, screen->surface, this->rect);
}