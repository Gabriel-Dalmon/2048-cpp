#include <iostream>
#include <conio.h>
#include <SDL.h>

#include "../../include/engine/SDLInputManager.h"
#include "../../data/globals.h"


SDLInputManager::SDLInputManager() {};


SDLInputManager::~SDLInputManager() {};


void SDLInputManager::update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        this->inputs[0] = 72;
                        break;
                    case SDLK_DOWN:
                        this->inputs[0] = 80;
                        break;
                    case SDLK_LEFT:
                        this->inputs[0] = 75;
                        break;
                    case SDLK_RIGHT:
                        this->inputs[0] = 77;
                        break;
                    case SDLK_ESCAPE:
                        this->inputs[1] = 27;
						break;
                }
            }
    }
}