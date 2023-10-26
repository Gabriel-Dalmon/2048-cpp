#pragma once

#include <vector>
#include "../../data/globals.h"
#include "Tile.h"
#include "GameObject.h"



class Board : public GameObject
{
public:
	std::vector<Tile*> grid;
	int gridSize[2];

	Board(int sideSize);
	~Board();

	int getGridLength(GridDimension lengthIndex);
	void updateGrid(int slideDirection[2]);
	void render();

private:

	void generateGrid(int gridSize[2]);
	std::vector<int> getFreeCells();
	void addRandomTile(int amountOfTiles);
	void slideTiles(int slideDirection[2]);
	void deleteGrid();
};