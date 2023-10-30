// 2048.cpp : Entrypoint
//

#include <iostream>
#include "include/gamelogic/Board.h"
#include "include/engine/ConsoleRenderer.h"
#include "include/engine/ConsoleInputManager.h"

int main()
{
    srand(time(nullptr));
    ConsoleRenderer* renderer = new ConsoleRenderer();
    ConsoleInputManager* inputManager = new ConsoleInputManager();
    int* inputs = inputManager->inputs;
    int gridSize = 0;

    std::cout << "Enter the grid size, (ex: 4 = 4x4 Grid): ";
    while (gridSize < 2 || gridSize > 100) {
        std::cin >> gridSize;
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Invalid gridSize entered, enter an integer smaller than 100 and larger than 1" << std::endl;
    }
    Board* board = new Board(gridSize);
    
    while (!board->isGameOver()) {
        renderer->render(board);
        inputManager->update();
        board->update(inputs);
    }

    renderer->render(board);
    std::cout << "           Game Over" << std::endl;
    if (board->isGameOver() == 2) {
        std::cout << "           \033[34mYou Won\033[0m" << std::endl;
    }
    else {
        std::cout << "           \033[31mYou Lost\033[0m" << std::endl;
    }

    delete inputManager;
    delete board;
    delete renderer;
}
