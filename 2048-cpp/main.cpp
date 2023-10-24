// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <conio.h>
#include "include/gamelogic/Board.h"
#include "include/engine/ConsoleRenderer.h"


int main()
{
    srand(time(nullptr));
    ConsoleRenderer* renderer = new ConsoleRenderer();
    Board* board = new Board(4);

    int isPlaying = 1;
    int input;
    int slideMovement[2];

    while (isPlaying == 1) {
        renderer->render(board);

        input = _getch();
        switch (input) {
            case 72: // up
                std::cout << "up" << std::endl;
			    slideMovement[0] = -1;
			    slideMovement[1] = 1;
			    break;
            case 80: // down
                std::cout << "down" << std::endl;
                slideMovement[0] = 1;
                slideMovement[1] = 1;
                break;
            case 75: // left
                std::cout << "left" << std::endl;
                slideMovement[0] = -1;
                slideMovement[1] = 0;
                break;
            case 77: // right
                std::cout << "right" << std::endl;
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
    }
    

    delete board;
    delete renderer;
    
}
