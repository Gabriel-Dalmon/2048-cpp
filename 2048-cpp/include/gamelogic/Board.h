#pragma once

#include "../utils/Vector2D.h"
#include "../../data/globals.h"
#include "Tile.h"

class Board
{
public:
	Vector2D<Tile*> grid;

	Board(int sideSize);
	~Board();

	void updateGrid(bool slideDirection[2]);

private:
	std::vector<int> getFreeCells();
	void addRandomTile(int amountOfTiles);
	void slideTiles(bool slideDirection[2]);
	void mergeTiles(Tile* currentTile, Tile* targetTile);
};