// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "include/gamelogic/Board.h"
#include "include/engine/ConsoleRenderer.h"

int main()
{
    srand(time(nullptr));
    ConsoleRenderer* renderer = new ConsoleRenderer();
    Board* board = new Board(4);

    renderer->render(board);

    delete board;
    delete renderer;
    
}
