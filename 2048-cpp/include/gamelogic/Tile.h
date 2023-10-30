#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "GameObject.h"

class Tile : public GameObject 
{
public:
	Tile();
	~Tile();

	int value;
	bool mergedAlready;
	SDL_Surface* sprite;
	TTF_Font* font;

	void(*renderPointer)(SDLScreen* screen);

	
	void render(SDLScreen* screen);
	//void render_empty(SDLScreen* screen);
	//void render_smth(SDLScreen* screen);
};