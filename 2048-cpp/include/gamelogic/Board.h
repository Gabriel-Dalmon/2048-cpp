#pragma once

#include <vector>
#include "../../data/globals.h"

class Board
{
public:
	std::vector<int> grid;
	int gridSize[2];

	Board(int sideSize);
	~Board();

	int getGridLength(GridDimension lengthIndex);
	void updateGrid(int slideDirection[2]);

private:

	void generateGrid(int gridSize[2]);
	std::vector<int> getFreeCells();
	void addRandomTile(int amountOfTiles);
	void slideTiles(int slideDirection[2]);
};