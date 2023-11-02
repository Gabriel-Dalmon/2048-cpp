#include <iostream>
#include <stdlib.h>

#include "../../include/gamelogic/Board.h"
#include "../../include/gamelogic/Tile.h"

Board::Board(int sideSize): grid(sideSize)
{
	SDL_Rect rect;
	this->rect = &rect;
	this->rect->x = 0;
	this->rect->y = 0;
	this->generateGrid();
	this->addRandomTile(2);
}

Board::~Board()
{
	deleteGrid();
}

void Board::render(SDLScreen* screen) 
{
	for (int i = 0; i < this->grid.getSingleSize(0) * this->grid.getSingleSize(0); i++) {
		this->grid[i]->render(screen);
	}
}

int Board::getGridLength(GridDimension lengthIndex)
{
	return this->grid.getSingleSize(lengthIndex);
}


void Board::update(int inputs[4])
{
	bool leftOrUpSlide, axis;
	switch (inputs[0]) {
	case 72: // up
		leftOrUpSlide = true;
		axis = true;
		this->slideTilesGeneric(leftOrUpSlide, axis);
		this->addRandomTile(1);
		break;
	case 80: // down
		leftOrUpSlide = false;
		axis = true;
		this->slideTilesGeneric(leftOrUpSlide, axis);
		this->addRandomTile(1);
		break;
	case 75: // leftaxis
		leftOrUpSlide = true;
		axis = false;
		this->slideTilesGeneric(leftOrUpSlide, axis);
		this->addRandomTile(1);
		break;
	case 77: // right
		leftOrUpSlide = false;
		axis = false;
		this->slideTilesGeneric(leftOrUpSlide, axis);
		this->addRandomTile(1);
		break;
	}
	//inputs[0] = 0;
}

void Board::generateGrid()
{
	int j = 0;
	for (int i = 0; i < this->grid.getSingleSize(WIDTH) * this->grid.getSingleSize(HEIGHT); i++)
	{
		this->grid[i] = new Tile;
		j = i % 4;
		this->grid[i]->rect->x =  j * 40;
		this->grid[i]->destRect->x =  j * 40;
		this->grid[i]->rect->y = (i - j) * 10;
		this->grid[i]->destRect->y = (i - j) * 10;
	}
}

void Board::deleteGrid()
{
	for (int i = 0; i < this->grid.getSingleSize(0) * this->grid.getSingleSize(1); i++) {
		delete this->grid[i];
	}
}

std::vector<int> Board::getFreeCells()
{
	std::vector<int> freeCells;
	for (int i = 0; i < this->grid.getSingleSize(0) * this->grid.getSingleSize(1); i++)
	{
		if (this->grid[i]->value == 0)
		{
			freeCells.push_back(i);
		}
	}
	return freeCells;
}

void Board::addRandomTile(int amountOfTiles)
{
	
	std::vector<int> freeCells = this->getFreeCells();
	for (int i = 0; i < amountOfTiles; i++) 
	{
		if (freeCells.size() > 0) {
			int randomFreeCellIndex = rand() % freeCells.size();
			int randomValue = 2 + 2*( rand() % 2); // 2 or 4
			this->grid[freeCells[randomFreeCellIndex]]->value = randomValue;
			this->grid[freeCells[randomFreeCellIndex]]->swap_render(1);
			freeCells.erase(freeCells.begin() + randomFreeCellIndex);
		}
		else {
			break;
		}
	}
}




void Board::mergeTiles(int currentTileCursor, int targetTileCursor) {
	Tile* currentTile = this->grid[currentTileCursor];
	Tile* targetTile = this->grid[targetTileCursor];
	int tmpX = targetTile->destRect->x;
	int tmpY = targetTile->destRect->y;
	targetTile->destRect->x = currentTile->destRect->x;
	targetTile->destRect->y = currentTile->destRect->y;
	currentTile->destRect->x = tmpX;
	currentTile->destRect->y = tmpY;
	currentTile->value += targetTile->value;
	currentTile->mergedAlready = targetTile->value; //if merging with 0, mergedAlready remains false
	currentTile->swap_render(1);
	targetTile->value = 0;
	targetTile->swap_render(0);
	this->grid[targetTileCursor] = currentTile;
	this->grid[currentTileCursor] = targetTile;
}


void Board::resetLockedTilesMergeStatus(bool isExpandDirection, bool axis) {
	int dimensionsIndex[2];
	for (int i = 0; i < this->grid.getSingleSize(axis); i++) {
		dimensionsIndex[axis] = i; //decides if i is row or column
		dimensionsIndex[!axis] = (this->grid.getSingleSize(!axis) - 1) * isExpandDirection;
		this->grid(dimensionsIndex[0], dimensionsIndex[1])->mergedAlready = false;
	}
}


void Board::slideTilesGeneric(bool leftOrUpSlide, bool axis) //axis : 1 = vertical slide, 0 = horizontal slide
{
	const bool rightOrDownSlide = !leftOrUpSlide;													//right/down : rightOrDownSlide = 1	;	left/up : rightOrDownSlide = 0
	const int cursorOffsetDirection = leftOrUpSlide * -1 + rightOrDownSlide * 1;					//right/down : offset = 1				;	left/up : offset = -1

	const bool oppositeAxis = !axis;																//left/right : oppositeAxis = 1			;	up/down : oppositeAxis = 0
	int row, column, * dimensionsIndex[2] = { &row, &column };										//left/right : dimIndex[0] = row; dimIndex[1] = column		;	up/down : dimIndex[0] = column; dimIndex[1] = row

	const int rowSlideDirection = cursorOffsetDirection * axis;
	const int columnSlideDirection = cursorOffsetDirection * oppositeAxis;

	const int gridSize[2] = { this->grid.getSingleSize(WIDTH), this->grid.getSingleSize(HEIGHT) };
	int slideOffset, cursor, targetCursor;
	Tile* currentTile, * slideTargetTile;

	this->resetLockedTilesMergeStatus(rightOrDownSlide, axis);

	//move tiles
	for (int i = 0; i < gridSize[axis]; i++) {
		*dimensionsIndex[axis] = i; //decides if i is row or column
		for (int j = 1; j < gridSize[oppositeAxis]; j++) {
			*dimensionsIndex[oppositeAxis] = (gridSize[oppositeAxis] - j - 1) * rightOrDownSlide + j * leftOrUpSlide; //decides if j is row or column and if it should be reverted

			cursor = row * gridSize[0] + column;

			currentTile = this->grid[cursor];
			currentTile->mergedAlready = false;

			if (currentTile->value) {
				slideOffset = 1;
				while (slideOffset - 1 < j) {
					targetCursor = (row + rowSlideDirection * (slideOffset)) * gridSize[0] + (column + columnSlideDirection * (slideOffset));
					slideTargetTile = this->grid[targetCursor];
					if (slideTargetTile->value == 0 || (currentTile->value == slideTargetTile->value && !slideTargetTile->mergedAlready && !currentTile->mergedAlready)) {
						this->mergeTiles(cursor, targetCursor);
						int x = (row + rowSlideDirection * (slideOffset));
						int y = (column + columnSlideDirection * (slideOffset));
					}
					else {
						slideOffset = j;
					}
					cursor = targetCursor;
					++slideOffset;
				}
			}
		}
	}
}

