#pragma once

#include "GameObject.h"

class Tile : public GameObject
{
public:
	Tile();
	~Tile();

	int value;
	bool mergedAlready;

	void render();
};