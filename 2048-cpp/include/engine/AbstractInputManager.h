#pragma once


class AbstractInputManager
{
public:
	AbstractInputManager() {};
	~AbstractInputManager() {};
	virtual int manageInput() = 0;
};
