#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>

#include "../../include/gamelogic/Tile.h"
#include "../../include/engine/SDLRenderer.h"


Tile::Tile() : GameObject() {
	this->value = 0;
	this->stuck = false;
	this->sprite = IMG_Load("src/assets/tile.png");
	this->rect->x = 0;
	this->rect->y = 0;
	this->rect->h = 40;
	this->rect->w = 40;
	this->font = TTF_OpenFont("fonts/ttf-bitstream-vera-1.10/Vera.ttf", 16);
}

Tile::~Tile() {}


void Tile::render(SDLScreen* screen) {
	char charValue = char(this->value);
	SDL_Color color = {255, 255, 255, 0};
	SDL_Surface* message = TTF_RenderText_Blended(this->font, &charValue, color);
	SDL_BlitSurface(this->sprite, NULL, screen->surface, this->rect);
}