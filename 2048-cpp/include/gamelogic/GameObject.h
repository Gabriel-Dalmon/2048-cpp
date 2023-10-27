#pragma once

#include <vector>

class GameObject
{
public:
	GameObject() {};
	~GameObject() {};

	int position[2] = { 0, 0 };

	virtual void render() {};
};