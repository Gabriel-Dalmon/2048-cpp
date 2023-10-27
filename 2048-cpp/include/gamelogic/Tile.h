#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "GameObject.h"

class Tile : public GameObject 
{
public:
	Tile();
	~Tile();

	int value;
	bool stuck;
	SDL_Surface* sprite;

	
	void render(SDLScreen* screen);
};