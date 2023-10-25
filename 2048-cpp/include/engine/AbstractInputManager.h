#pragma once


class AbstractInputManager
{
public:
	AbstractInputManager() {};
	~AbstractInputManager() {};
	virtual void manageInput(int* slideMovement) = 0;
};
