#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include "../../include/engine/ConsoleRenderer.h"
#include "../../include/gamelogic/Board.h"
#include "../../data/globals.h"

std::map<int, std::string> tilesColors {
	{ 0, "37" },
	{ 2, "96" },
	{ 4, "31" },
	{ 8, "32" },
	{ 16, "33" },
	{ 32, "34" },
	{ 64, "35" },
	{ 128, "36" },
	{ 256, "95" },
	{ 512, "92" },
	{ 1024, "93" },
	{ 2048, "94" },
};

void ConsoleRenderer::render(Board* board) {
	system("cls");
	std::string tileColor = "0";
	std::string topLine;
	std::string midLine;
	std::string valueLine;
	std::string bottomLine;
	for (int y = 0; y < board->grid.getSingleSize(HEIGHT); y++) {
		topLine = "";
		midLine = "";
		valueLine = "";
		bottomLine = "";
		for (int x = 0; x < board->grid.getSingleSize(WIDTH); x++) {
			std::string tileValue = std::to_string(board->grid(y, x)->value);
			tileColor = "\033[" + tilesColors[board->grid(y, x)->value] + "m";
			topLine += tileColor + "ÉÍÍÍÍÍÍ»";
			midLine += tileColor + "º      º";
			
			std::string frontSpace(3 - ceil(tileValue.length() / 2.0), ' ');
			std::string backSpace(3 - floor(tileValue.length() / 2.0), ' ');
			valueLine += tileColor + "º" + frontSpace + tileValue + backSpace + "º";

			bottomLine += tileColor + "ÈÍÍÍÍÍÍ¼";
		}
		std::cout << topLine << std::endl << midLine << std::endl << valueLine << std::endl << midLine << std::endl << bottomLine << std::endl;
	}
	std::cout << "\033[0m" << std::endl;
}

//Windows 1252 - Graphic Extension Symbols :   Ì = ╠     » = ╗      º = ║     Í = ═     É = ╔      ¼ = ╝      È = ╚