#pragma once

#include <vector>
#include "../../data/globals.h"
#include "Tile.h"
#include "GameObject.h"
#include "../utils/Vector2D.h"



class Board : public GameObject
{
public:
	Vector2D<Tile*> grid;
	//int gridSize[2];

	Board(int sideSize);
	~Board();

	int getGridLength(GridDimension lengthIndex);
	void update(int slideDirection[4]);
	void render(SDLScreen* screen);
	int isGameOver();
	void setGridToTemplate(Vector2D<int> gridTemplate);

private:

	bool hasGridTileValue(int tileValue);
	SDL_Surface* background;
	void generateGrid();
	std::vector<int> getFreeCells();
	void addRandomTile(int amountOfTiles);
	void deleteGrid();
	void slideTilesGeneric(bool leftOrUpSlide, bool axis);
	void mergeTiles(int currentTileCursor, int targetTileCursor); //swap the tiles pointers in the board, the target tile value is added to the current tile value, the target tile value is set to 0, the moving tile is set to locked(can't be merged again)
	void resetLockedTilesMergeStatus(bool isExpandDirection, bool axis);
};