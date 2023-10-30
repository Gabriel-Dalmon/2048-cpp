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
	int isGameOver(); //returns 0 if game is not over, 1 if game is over and lost, 2 if game is over and won

private:
	std::vector<int> getFreeCells(); //returns the list of cursor indexes of tiles that have a value of 0
	void generateGrid();
	bool hasGridTileValue(int tileValue);	
	void addRandomTile(int amountOfTiles);
	void slideTilesLeft();
	void slideTilesRight();
	void slideTilesUp();
	void slideTilesDown();
	void slideTiles(bool leftOrUpSlide, bool axis);
	void mergeTiles(int currentTileCursor, int targetTileCursor); //swap the tiles pointers in the board, the target tile value is added to the current tile value, the target tile value is set to 0, the moving tile is set to locked(can't be merged again)
	void resetLockedTilesMergeStatus(bool isExpandDirection, bool axis);
};