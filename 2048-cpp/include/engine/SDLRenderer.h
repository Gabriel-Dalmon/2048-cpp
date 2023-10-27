#pragma once

#include "../../include/engine/AbstractRenderer.h"
#include "../../data/globals.h"



class SDLRenderer : public AbstractRenderer
{
public:
	SDLScreen* screen;

	SDLRenderer();
	~SDLRenderer();
	void render(GameObject* object);
};