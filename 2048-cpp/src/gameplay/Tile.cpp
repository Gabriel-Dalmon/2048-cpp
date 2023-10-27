#include <SDL.h>

#include "../../include/gamelogic/Tile.h"
#include "../../include/engine/SDLRenderer.h"


Tile::Tile() : GameObject() {
	this->value = 0;
	this->stuck = false;
	this->sprite = IMG_Load("assets/tile.png");
}

Tile::~Tile() {}


void Tile::render(SDLScreen* screen) {
	SDL_Rect testRect;
	testRect.x = 0; testRect.y = 0;
	testRect.w = 40; testRect.h = 40;
	SDL_BlitSurface(this->sprite, NULL, screen->surface, &testRect);
}