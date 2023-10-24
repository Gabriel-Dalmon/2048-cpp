#pragma once

#include "../gamelogic/Board.h"

class AbstractRenderer
{
public:
	AbstractRenderer() {};
	~AbstractRenderer() {};
	virtual void render(Board* board) = 0;
};
