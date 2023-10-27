// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <conio.h>
#include "include/gamelogic/Board.h"
#include "include/engine/SDLRenderer.h"
#include "include/engine/ConsoleInputManager.h"


int main(int argc, char* argv[1])
{
    std::cout << "sgohzegohol" << std::endl;
    srand(time(nullptr));
    SDLRenderer* renderer = new SDLRenderer();
    ConsoleInputManager* inputManager = new ConsoleInputManager();
    Board* board = new Board(4);

    int isPlaying = 1;
    int input;
    int slideMovement[2];

    while (isPlaying == 1) {
        renderer->render(board);

        inputManager->manageInput(slideMovement);
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
