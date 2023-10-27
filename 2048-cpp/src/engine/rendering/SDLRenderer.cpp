#include <Windows.h>

#include "../../../include/engine/SDLRenderer.h"

SDLRenderer::SDLRenderer() {
	SDL_Init(SDL_INIT_VIDEO);
	IMG_INIT_PNG;
	this->screen = new SDLScreen();
	this->screen->window = SDL_CreateWindow("main", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SDL_WINDOW_RESIZABLE);
	this->screen->renderer = SDL_CreateRenderer(this->screen->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	this->screen->surface = SDL_GetWindowSurface(this->screen->window);
}

SDLRenderer::~SDLRenderer() {
	free(this->screen->surface); // pas sur que ca fonctionne / soit clean / soit util
	SDL_DestroyWindow(this->screen->window);
	SDL_DestroyRenderer(this->screen->renderer);
	delete this->screen;
}

void SDLRenderer::render(GameObject* object){
	object->render(this->screen);
}