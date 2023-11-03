#pragma once
#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <unordered_map>

#include "GameObject.h"

class TextObject : public GameObject
{
public:
	TextObject(const char* text, SDL_Rect* rect, const char* fontPath, SDL_Color color, int fontSize);
	~TextObject();

	SDL_Surface* surface;

	void render(SDLScreen* screen);
};