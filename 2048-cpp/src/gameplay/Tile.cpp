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
	this->renderPointer = render_empty;
}

Tile::~Tile() {}


void Tile::render(SDLScreen* screen) {
	this->renderPointer(screen);
}

void render_empty(SDLScreen* screen){}


void render_smth(SDLScreen* screen, Tile* tile){
	char numberstring[(((sizeof(tile->value)) * CHAR_BIT) + 2) / 3 + 2];
	sprintf_s(numberstring, "%d", tile->value);

	SDL_Color color = { 255, 255, 255, 0 };
	SDL_Surface* message = TTF_RenderText_Blended(tile->font, numberstring, color);
	SDL_BlitSurface(tile->sprite, NULL, screen->surface, tile->rect);
	SDL_BlitSurface(message, NULL, screen->surface, tile->rect);
}