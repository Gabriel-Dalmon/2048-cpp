#pragma once

#include "AbstractInputManager.h"

class ConsoleInputManager : public AbstractInputManager
{
public:
	ConsoleInputManager() {};
	~ConsoleInputManager() {};
	void manageInput(int* slideMovement);
};