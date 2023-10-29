#include <iostream>

#include "../../include/engine/ConsoleRenderer.h"
#include "../../include/gamelogic/Board.h"
#include "../../data/globals.h"

void ConsoleRenderer::render(Board* board) {
	//system("cls");
	for (int y = 0; y < board->grid.getSingleSize(HEIGHT); y++) {
		for (int i = 0; i < board->grid.getSingleSize(WIDTH); i++) {
			std::cout << "ÉÍÍÍÍÍÍ»";
		}
		std::cout << std::endl;

		for (int i = 0; i < board->grid.getSingleSize(WIDTH); i++) {
			std::cout << "º      º";
		}
		std::cout << std::endl;

		for (int x = 0; x < board->grid.getSingleSize(WIDTH); x++) {
			
			
			std::cout << "º   " << board->grid(y, x)->value << "   º";

		}
		std::cout << std::endl;

		for (int i = 0; i < board->grid.getSingleSize(WIDTH); i++) {
			std::cout << "º      º";
		}
		std::cout << std::endl;

		for (int i = 0; i < board->grid.getSingleSize(WIDTH); i++) {
			std::cout << "ÈÍÍÍÍÍÍ¼" << std::endl;
		}
		std::cout << std::endl;
	}
}

//Windows 1252 - Graphic Extension Symbols :   Ì = ╠     » = ╗      º = ║     Í = ═     É = ╔      ¼ = ╝      È = ╚