#pragma once

#include <vector>
#include "../../data/globals.h"

struct Tile
{
	int value;
	int mergedThisTurn;
};

class Board
{
public:
	std::vector< Tile > grid;
	int gridSize[2];

	Board(int sideSize);
	~Board();

	int getGridLength( GridDimension lengthIndex );
	void updateGrid( int slideDirection );
	
private:
	
	void generateGrid( int gridSize[2] );
	std::vector<int> getFreeCells();
	void addRandomTile( int amountOfTiles );
	void slideTiles( int slideDirection );
};
