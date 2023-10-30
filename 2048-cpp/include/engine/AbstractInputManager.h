#pragma once


class AbstractInputManager
{
public:
	int inputs[4] = {0,0,0,0};
	AbstractInputManager() {};
	~AbstractInputManager() {};
	virtual void update() = 0;
};
