// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <conio.h>
#include <SDL_image.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <Windows.h>
#include "include/gamelogic/Board.h"
#include "include/engine/SDLRenderer.h"
#include "include/engine/SDLInputManager.h"
#include "include/engine/ConsoleRenderer.h"



int main(int argc, char* argv[1])
{
    //srand(time(nullptr));
    ConsoleRenderer* consoleRenderer = new ConsoleRenderer();
    SDLRenderer* renderer = new SDLRenderer();
    SDLInputManager* inputManager = new SDLInputManager();
    Board* board = new Board(4);

    int isPlaying = 1;
    int* inputs = inputManager->inputs;
    /*
    Vector2D<int> gridTemplate(4);
    std::cout << "normal4" << std::endl;

    for (int i = 0; i < gridTemplate.size(); ++i) {
        gridTemplate[i] = 2048;
    }
    board->setGridToTemplate(gridTemplate);*/
    while (! board->isGameOver()) {
        renderer->render(board);
        if (inputs[0]) {
            consoleRenderer->render(board);
            inputs[0] = 0;
        }
        inputManager->update();
        board->update(inputs);
    }

    if (board->isGameOver() == 1) {
        GameObject fontScreen;
        std::cout << "hhhhhhhhhhhhhhhhhhh";
    }
    else {
        
    }
    
    
    

    delete inputManager;
    delete board;
    delete renderer;
    delete consoleRenderer;

    
    return 0;
}
