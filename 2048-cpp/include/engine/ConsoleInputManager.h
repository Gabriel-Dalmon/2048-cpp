#pragma once

#include "AbstractInputManager.h"

class ConsoleInputManager : public AbstractInputManager
{
public:
	int inputs[4] = { 0,0,0,0 };
	ConsoleInputManager();
	~ConsoleInputManager();
	void update();
};