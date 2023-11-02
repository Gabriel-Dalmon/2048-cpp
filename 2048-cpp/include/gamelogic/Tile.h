#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <unordered_map>

#include "GameObject.h"

class Tile : public GameObject 
{
public:
	Tile();
	~Tile();

	int value;
	bool mergedAlready;
	
	
	void(Tile::* renderArray[2])(SDLScreen*);

	void(Tile::*renderPointer)(SDLScreen* screen);

	SDL_Rect* destRect;

	
	void render(SDLScreen* screen);
	void swap_render(int value);

private:
	void render_empty(SDLScreen* screen);
	void render_smth(SDLScreen* screen);
	void animate();
	static std::unordered_map<int, SDL_Surface*> tilesSpritesMap;
};