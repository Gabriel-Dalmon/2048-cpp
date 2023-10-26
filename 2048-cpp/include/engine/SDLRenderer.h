#pragma once

#include <SDL.h>

#include "../../include/engine/AbstractRenderer.h"


class SDLRenderer : public AbstractRenderer
{
public:
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDLRenderer();
	~SDLRenderer();
	void render(Board* board);
};