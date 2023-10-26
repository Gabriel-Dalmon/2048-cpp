#include <Windows.h>

#include "../../../include/engine/SDLRenderer.h"

SDLRenderer::SDLRenderer() {
	this->window = SDL_CreateWindow("main", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SDL_WINDOW_RESIZABLE);
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

SDLRenderer::~SDLRenderer() {
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
}

void SDLRenderer::render(Board* board){

}