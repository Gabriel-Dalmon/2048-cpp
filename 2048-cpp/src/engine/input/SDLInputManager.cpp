#include <iostream>
#include <conio.h>
#include <SDL.h>

#include "../../include/engine/SDLInputManager.h"
#include "../../data/globals.h"


SDLInputManager::SDLInputManager() {};


SDLInputManager::~SDLInputManager() {};


int SDLInputManager::manageInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDLK_UP:
            return 1;
        case SDLK_LEFT:
            return 2;
        case SDLK_RIGHT:
            return 3;
        case SDLK_DOWN:
            return 4;
        }
    }
    return -1;
}