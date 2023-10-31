#include <Windows.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

#include "../../../include/engine/SDLRenderer.h"

SDLRenderer::SDLRenderer() {
	SDL_Init(SDL_INIT_VIDEO);
	IMG_INIT_PNG;
	TTF_Init();
	this->screen = new SDLScreen();
	//this->screen->window = SDL_CreateWindow("main", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SDL_WINDOW_RESIZABLE);
	this->screen->window = SDL_CreateWindow("main", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_RESIZABLE);
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
	SDL_RenderClear(this->screen->renderer);
	SDL_FillRect(this->screen->surface, NULL, 0x000000);
	object->render(this->screen);
	SDL_UpdateWindowSurface(this->screen->window);
}