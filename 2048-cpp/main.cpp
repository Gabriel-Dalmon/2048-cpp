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
    int* inputs = inputManager->inputs;
    bool slideMovement[2];

    while (isPlaying == !board->isGameOver()) {
        renderer->render(board);
        inputManager->update();
        board->update(inputs);
    }
    renderer->render(board);
    std::cout << "Game Over" << std::endl;
    if (board->isGameOver() == 2) {
        std::cout << "You Won" << std::endl;
    }
    else {
        std::cout << "You Lost" << std::endl;
    }

    delete inputManager;
    delete board;
    delete renderer;
    
}
