#pragma once

#include "AbstractInputManager.h"

class SDLInputManager : public AbstractInputManager
{
public:
	SDLInputManager() {};
	~SDLInputManager() {};
	int manageInput();
};