#include <iostream>
#include "../../include/gamelogic/Board.h"

Board::Board(int sideSize): grid(sideSize)
{
	this->generateGrid();
	this->addRandomTile(2);
}

Board::~Board()
{}


void Board::updateGrid(bool slideDirection[2])
{
	this->slideTiles(slideDirection[0], slideDirection[1]);
	this->addRandomTile(2);

}


std::vector<int> Board::getFreeCells()
{
	std::vector<int> freeCells;
	for (int i = 0; i < this->grid.getSingleSize(WIDTH) * this->grid.getSingleSize(HEIGHT); i++)
	{
		if (this->grid[i]->value == 0)
		{
			freeCells.push_back(i);
		}
	}
	return freeCells;
}

bool Board::hasGridTileValue(int tileValue) {
	for (int i = 0; i < this->grid.size(); i++) {
		if (this->grid[i]->value == tileValue) {
			return true;
		}
	}
	return false;
}

void Board::generateGrid()
{
	for (int i = 0; i < this->grid.getSingleSize(WIDTH) * this->grid.getSingleSize(HEIGHT); i++)
	{
		this->grid[i] = new Tile;
	}
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
			freeCells.erase(freeCells.begin() + randomFreeCellIndex);
		}
		else {
			break;
		}
	}
}

void Board::resetLockedTilesMergeStatus(bool isExpandDirection, bool axis) {
	int dimensionsIndex[2];
	for (int i = 0; i < this->grid.getSingleSize(axis) ; i++) {
		dimensionsIndex[axis] = i; //decides if i is row or column
		dimensionsIndex[!axis] = (this->grid.getSingleSize(!axis) - 1) * isExpandDirection;
		this->grid(dimensionsIndex[0], dimensionsIndex[1])->mergedAlready = false;
	}
}

void Board::mergeTiles(int currentTileCursor, int targetTileCursor) {
	Tile* currentTile = this->grid[currentTileCursor];
	Tile* targetTile = this->grid[targetTileCursor];
	currentTile->value += targetTile->value;
	currentTile->mergedAlready = targetTile->value; //if merging with 0, mergedAlready remains false
	targetTile->value = 0;
	this->grid[targetTileCursor] = currentTile;
	this->grid[currentTileCursor] = targetTile;
}

void Board::slideTiles(bool leftOrUpSlide, bool axis)
{
	const bool rightOrDownSlide = !leftOrUpSlide;													//right/down : rightOrDownSlide = 1	;	left/up : rightOrDownSlide = 0
	const int cursorOffsetDirection = leftOrUpSlide * -1 + rightOrDownSlide * 1;					//right/down : offset = 1				;	left/up : offset = -1

	const bool oppositeAxis = !axis;																//left/right : oppositeAxis = 1			;	up/down : oppositeAxis = 0
	int row, column, *dimensionsIndex[2] = { &row, &column };										//left/right : dimIndex[0] = row; dimIndex[1] = column		;	up/down : dimIndex[0] = column; dimIndex[1] = row

	const int rowSlideDirection = cursorOffsetDirection * axis;
	const int columnSlideDirection = cursorOffsetDirection * oppositeAxis;

	const int gridSize[2] = { this->grid.getSingleSize(WIDTH), this->grid.getSingleSize(HEIGHT) };
	int slideOffset, cursor, targetCursor;
	Tile *currentTile, *slideTargetTile;

	this->resetLockedTilesMergeStatus(rightOrDownSlide, axis);

	//move tiles
	for (int i = 0; i < gridSize[axis]; i++) {
		*dimensionsIndex[axis] = i; //decides if i is row or column
		for (int j = 1; j < gridSize[oppositeAxis]; j++) {
			*dimensionsIndex[oppositeAxis] = (gridSize[oppositeAxis] - j - 1 ) * rightOrDownSlide + j * leftOrUpSlide; //decides if j is row or column and if it should be reverted
			slideOffset = 0;
			cursor = (row + rowSlideDirection * slideOffset) * gridSize[0] + (column + columnSlideDirection * slideOffset);
			
			currentTile = this->grid[cursor];
			currentTile->mergedAlready = false;

			if (currentTile->value) {
				++slideOffset;
				targetCursor = (row + rowSlideDirection * (slideOffset)) * gridSize[0] + (column + columnSlideDirection * (slideOffset));
				
				while(slideOffset - 1 < gridSize[oppositeAxis] - (gridSize[oppositeAxis] - j)) {
					slideTargetTile = this->grid[targetCursor];
					if (slideTargetTile->value == 0 || (currentTile->value == slideTargetTile->value && !slideTargetTile->mergedAlready && !currentTile->mergedAlready)) {
						this->mergeTiles(cursor, targetCursor);
					}
					else {
						slideOffset = gridSize[oppositeAxis] + 9;
					}
					cursor = targetCursor;
					++slideOffset;
					targetCursor = (row + rowSlideDirection * slideOffset) * gridSize[0] + (column + columnSlideDirection * slideOffset);
				}				  
			}
		}
	}

}

int Board::isGameOver()
{
	int gridWidth = this->grid.getSingleSize(WIDTH);
	int gridHeight = this->grid.getSingleSize(HEIGHT);
	if (!this->hasGridTileValue(0)) {
		for (int row = 0; row < gridWidth; ++row) {
			for (int column = 0; column < gridHeight - 1; ++column) {
				if (this->grid(row, column)->value == this->grid(row, column + 1)->value) {
					return 0;
				}
			}
		}
		for (int column = 0; column < gridHeight; ++column) {
			for (int row = 0; row < gridWidth - 1; ++row) {
				if (this->grid(row, column)->value == this->grid(row + 1, column)->value) {
					return 0;
				}
			}
		}
		return 1;
	}

	return this->hasGridTileValue(2048)*2;
}