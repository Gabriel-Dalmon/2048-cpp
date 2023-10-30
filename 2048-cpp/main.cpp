// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <conio.h>
#include "include/gamelogic/Board.h"
#include "include/engine/SDLRenderer.h"
#include "include/engine/SDLInputManager.h"
#include <SDL_image.h>
#include <SDL.h>


int main(int argc, char* argv[1])
{
    srand(time(nullptr));
    SDLRenderer* renderer = new SDLRenderer();
    SDLInputManager* inputManager = new SDLInputManager();
    Board* board = new Board(4);

    int isPlaying = 1;
    int input;
    int slideMovement[2];

    while (isPlaying == 1) {
        renderer->render(board);

        slideMovement[0] = inputManager->manageInput();
        board->updateGrid(slideMovement);
        slideMovement[0] = 0;
        slideMovement[1] = 0;
        input = 0;
    }
    

    delete inputManager;
    delete board;
    delete renderer;
    
    return 0;
}
