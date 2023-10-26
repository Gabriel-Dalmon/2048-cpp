#pragma once

#include <vector>

class GameObject
{
public :
	GameObject() {};
	~GameObject() {};

	std::vector<int> position;

	virtual void render() {};
};