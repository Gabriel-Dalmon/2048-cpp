// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <conio.h>
#include "include/gamelogic/Board.h"
#include "include/engine/ConsoleRenderer.h"
#include "include/engine/ConsoleInputManager.h"


int main()
{
    srand(time(nullptr));
    ConsoleRenderer* renderer = new ConsoleRenderer();
    ConsoleInputManager* inputManager = new ConsoleInputManager();
    Board* board = new Board(4);

    int isPlaying = 1;
    int input;
    int slideMovement[2];

    while (isPlaying == 1) {
        renderer->render(board);

        input = _getch();
        switch (input) {
            case 72: // up
			    slideMovement[0] = -1;
			    slideMovement[1] = 1;
			    break;
            case 80: // down
                slideMovement[0] = 1;
                slideMovement[1] = 1;
                break;
            case 75: // left
                slideMovement[0] = -1;
                slideMovement[1] = 0;
                break;
            case 77: // right
                slideMovement[0] = 1;
				slideMovement[1] = 0;
				break;
            default :
                slideMovement[0] = 0;
                slideMovement[1] = 0;
                break;
        }
        board->updateGrid(slideMovement);
        slideMovement[0] = 0;
        slideMovement[1] = 0;
        input = 0;
    }
    

    delete inputManager;
    delete board;
    delete renderer;
    
}
