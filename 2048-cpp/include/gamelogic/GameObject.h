#pragma once

#include <vector>

#include "../../data/globals.h"


class GameObject
{
public :
	GameObject() {};
	~GameObject() {};

	SDL_Rect* rect;

	virtual void render(SDLScreen* screen) {};
};