#pragma once

#include <SDL.h>

enum GridDimension {
	WIDTH = 0,
	HEIGHT = 1
};

typedef struct SDLScreen {
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Surface* surface;
};