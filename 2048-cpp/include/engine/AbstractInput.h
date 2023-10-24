#pragma once

#include "../gamelogic/Board.h"

class AbstractInput
{
public:
	AbstractInput() {};
	~AbstractInput() {};
	virtual int manageInput() = 0;
};
