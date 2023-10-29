// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <conio.h>
#include "include/gamelogic/Board.h"
#include "include/engine/ConsoleRenderer.h"
#include "include/engine/ConsoleInputManager.h"
#include "include/utils/Vector2D.h"
#include<windows.h>

int main()
{
    //srand(time(nullptr));
    ConsoleRenderer* renderer = new ConsoleRenderer();
    ConsoleInputManager* inputManager = new ConsoleInputManager();
    Board* board = new Board(4);

    int isPlaying = 1;
    int input;
    bool slideMovement[2];

    while (isPlaying == 1) {
        renderer->render(board);
        input = _getch();
        switch (input) {
            case 72: // up
			    slideMovement[0] = true;
			    slideMovement[1] = true;
                board->updateGrid(slideMovement);
			    break;
            case 80: // down
                slideMovement[0] = false;
                slideMovement[1] = true;
                board->updateGrid(slideMovement);
                break;
            case 75: // left
                slideMovement[0] = true;
                slideMovement[1] = false;
                board->updateGrid(slideMovement);
                break;
            case 77: // right
                slideMovement[0] = false;
				slideMovement[1] = false;
                board->updateGrid(slideMovement);
				break;
        }
        isPlaying = !board->isGameOver();
    }
    std::cout << "Game Over" << std::endl;

    delete inputManager;
    delete board;
    delete renderer;
    
}
