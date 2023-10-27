#pragma once

#include "../gamelogic/Board.h"

class AbstractRenderer
{
public:
	AbstractRenderer() {};
	~AbstractRenderer() {};
	virtual void render(GameObject* object) = 0;
};
