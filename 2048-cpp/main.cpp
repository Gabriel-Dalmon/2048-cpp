// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <conio.h>
#include <thread>
#include <mutex>
#include <chrono>
#include "include/gamelogic/Board.h"
#include "include/engine/SDLRenderer.h"
#include "include/engine/SDLInputManager.h"
#include "include/engine/ConsoleRenderer.h"
#include <SDL_image.h>
#include <SDL.h>

std::mutex m;

void renderLoop(bool* isRunning, Board* board) {
    ConsoleRenderer* consoleRenderer = new ConsoleRenderer();
    SDLRenderer* renderer = new SDLRenderer();
    while (*isRunning) {
        m.lock();
        renderer->render(board);
        consoleRenderer->render(board);
        m.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    delete consoleRenderer;
    delete renderer;
}

void logicLoop(bool* isRunning, Board* board) {
    SDLInputManager* inputManager = new SDLInputManager();
    int* inputs = inputManager->inputs;
    while (*isRunning) {
        inputManager->update();
        m.lock();
        board->update(inputs);
        m.unlock();
    }
    delete inputManager;
}

int main(int argc, char* argv[1])
{
    //srand(time(nullptr));
    
    Board* board = new Board(4);

    bool isRunning = true;  

    std::thread logicLoopThread(logicLoop, &isRunning, board);
    std::thread renderLoopThread(renderLoop, &isRunning, board);

    logicLoopThread.join();
    renderLoopThread.join();
    
    delete board;
   
    return 0;
}
