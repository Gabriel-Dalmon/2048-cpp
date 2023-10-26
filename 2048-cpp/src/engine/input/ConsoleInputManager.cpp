#include <iostream>
#include <conio.h>

#include "../../../include/engine/ConsoleInputManager.h"
#include "../../../data/globals.h"

 int ConsoleInputManager::manageInput()
{
	 int input = _getch();
	 switch (input) {
	 case 72: //up
		 return 1;
		 break;

	 case 75: //left
		 return 2;
		 break;

	 case 77: //right
		 return 3;
		 break;

	 case 80: //down
		 return 4;
		 break;
	 }
	 return 0;
}