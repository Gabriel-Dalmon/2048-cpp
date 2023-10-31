#pragma once

#include "AbstractInputManager.h"

class SDLInputManager : public AbstractInputManager
{
public:
	int inputs[4] = { 0,0,0,0 };
	SDLInputManager();
	~SDLInputManager();
	void update();
};