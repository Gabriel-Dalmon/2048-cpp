#include <iostream>
#include <conio.h>

#include "../../include/engine/ConsoleInputManager.h"
#include "../../data/globals.h"

// void ConsoleInputManager::manageInput(int* slideMovement)
//{
//     int input = _getch();
//     switch (input) {
//     case 72: // up
//         slideMovement[0] = -1;
//         slideMovement[1] = 1;
//         break;
//     case 80: // down
//         slideMovement[0] = 1;
//         slideMovement[1] = 1;
//         break;
//     case 75: // left
//         slideMovement[0] = -1;
//         slideMovement[1] = 0;
//         break;
//     case 77: // right
//         slideMovement[0] = 1;
//         slideMovement[1] = 0;
//         break;
//     default:
//         slideMovement[0] = 0;
//         slideMovement[1] = 0;
//         break;
//     }
//}