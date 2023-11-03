#include <conio.h>

#include "../../include/engine/ConsoleInputManager.h"

ConsoleInputManager::ConsoleInputManager() {};

ConsoleInputManager::~ConsoleInputManager() {};


void ConsoleInputManager::update()
{
	this->inputs[0] = _getch();
}