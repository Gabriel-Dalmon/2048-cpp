#include <iostream>
#include <conio.h>

#include "../../../include/engine/ConsoleInputManager.h"
#include "../../../data/globals.h"


ConsoleInputManager::ConsoleInputManager() {};

ConsoleInputManager::~ConsoleInputManager() {};


 void ConsoleInputManager::update()
{
	 this->inputs[0] = _getch();
}