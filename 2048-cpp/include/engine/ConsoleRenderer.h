#pragma once

#include "AbstractRenderer.h"

class ConsoleRenderer : public AbstractRenderer
{
public:
	ConsoleRenderer() {};
	~ConsoleRenderer() {};
	void render(GameObject* object);
};