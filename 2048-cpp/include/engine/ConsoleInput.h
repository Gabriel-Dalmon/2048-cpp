#pragma once

#include "AbstractInput.h"

class ConsoleInput : public AbstractInput
{
public:
	ConsoleInput() {};
	~ConsoleInput() {};
	int manageInput();
};