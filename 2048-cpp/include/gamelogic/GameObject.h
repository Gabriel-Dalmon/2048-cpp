#pragma once

#include <vector>

#include "../../data/globals.h"

struct Position
{
	int x;
	int y;
};

class GameObject
{
public :
	GameObject() {};
	~GameObject() {};

	Position position;

	virtual void render(SDLScreen* screen) {};
};