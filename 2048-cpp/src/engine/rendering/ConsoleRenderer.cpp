#include <iostream>
#include <cmath>

#include "../../include/engine/ConsoleRenderer.h"
#include "../../include/gamelogic/Board.h"
#include "../../data/globals.h"

std::string operator * (std::string a, unsigned int b) {
	std::string output = "";
	while (b--) {
		output += a;
	}
	return output;
}


void ConsoleRenderer::render(Board* board) {
	int boardWidth = board->getGridLength(WIDTH);
	system("cls");
	for (int y = 0; y < board->getGridLength(HEIGHT); y++) {
		for (int x = 0; x < boardWidth; x++) {
			std::cout << board->grid[y * boardWidth + x].value << (board->grid[y * boardWidth + x].value > 0 ? (std::string(" ") * (6 - int(log10(board->grid[y * boardWidth + x].value)))) : "      ");
		}
		std::cout << std::endl;
	}
}