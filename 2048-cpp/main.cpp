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

    while (isPlaying == 1) {
        renderer->render(board);

        input = _getch();
        board->updateGrid(input);
    }
    

    delete board;
    delete renderer;
    
}
