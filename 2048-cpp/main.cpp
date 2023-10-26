// 2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <conio.h>
#include "include/gamelogic/Board.h"
#include "include/engine/ConsoleRenderer.h"
#include "include/engine/ConsoleInputManager.h"
#include "include/utils/Vector2D.h"

/*template <typename T>
class Vector2D : public std::vector<T>
{
public:
    int iSize[2]; // [0] = width, [1] = height

    Vector2D(int size): std::vector<T>(size * size) {
        this->iSize[0] = size;
        this->iSize[1] = size;
    };
    Vector2D(int width, int height): std::vector<T>(width * height) {
        this->iSize[0] = width;
        this->iSize[1] = height;
    };

    void resize(int size) {
        this->resize(size, size);
    };
    void resize(int width, int height) {
        this->iSize[0] = width;
        this->iSize[1] = height;
        this->std::vector<T>::resize(width * height);
    };

    int getVectorLength(GridDimension lengthIndex) {
        return this->iSize[lengthIndex];
    };

    T& operator()(int row, int col) {
        return (*this)[row * this->iSize[0] + col];
    };

    void setValue(int row, int col, T value) {
        (*this)[row * this->iSize[0] + col] = value;
    }
    ;
    T getValue(int row, int col) {
        return (*this)[row * this->iSize[0] + col];
    };
};*/


int main()
{
    srand(time(nullptr));
    ConsoleRenderer* renderer = new ConsoleRenderer();
    ConsoleInputManager* inputManager = new ConsoleInputManager();
    Board* board = new Board(4);

    int isPlaying = 1;
    int input;
    int slideMovement[2];

    Vector2D<int> vectTwoD(4);

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
    }
    

    delete inputManager;
    delete board;
    delete renderer;
    
}
