// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "include/gamelogic/Board.h"
#include "include/engine/ConsoleRenderer.h"
#include "include/engine/ConsoleInput.h"


int main()
{
    srand(time(nullptr));
    ConsoleRenderer* renderer = new ConsoleRenderer();
    ConsoleInput* inputManager = new ConsoleInput();
    Board* board = new Board(4);

    int isPlaying = 1;
    int input;

    while (isPlaying == 1) {
        renderer->render(board);

        input = inputManager->manageInput();
        if(input == 1 || input == 2 || input == 3 || input == 4 ) {
            board->updateGrid(input);
        }
    }
    

    delete inputManager;
    delete board;
    delete renderer;
    
}
