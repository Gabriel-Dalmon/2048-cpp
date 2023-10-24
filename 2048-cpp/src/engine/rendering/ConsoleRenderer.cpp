#include <iostream>

#include "../../include/engine/ConsoleRenderer.h"
#include "../../include/gamelogic/Board.h"
#include "../../data/globals.h"

void ConsoleRenderer::render(Board* board){	
	int boardWidth = board->getGridLength(WIDTH);
	//system("cls");
	for (int y = 0; y < board->getGridLength(HEIGHT); y++) {
		for (int x = 0; x < boardWidth; x++) {
			std::cout << board->grid[y * boardWidth + x] << " ";
		}
		std::cout << std::endl;
	}
}