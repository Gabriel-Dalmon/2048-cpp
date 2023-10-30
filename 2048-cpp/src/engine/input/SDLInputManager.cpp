#include <iostream>
#include <conio.h>

#include "../../include/engine/SDLInputManager.h"
#include "../../data/globals.h"

int SDLInputManager::manageInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDLK_UP:
            return 1;
            break;
        case SDLK_LEFT:
            return 2;
            break;
        case SDLK_RIGHT:
            return 3;
            break;
        case SDLK_DOWN:
            return 4;
            break;
        }
    }
    
}