#pragma once

#include "AbstractInputManager.h"

class ConsoleInputManager : public AbstractInputManager
{
public:
	ConsoleInputManager() {};
	~ConsoleInputManager() {};
	int manageInput();
};