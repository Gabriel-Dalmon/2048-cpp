#define row dimensionsIndex[0]
#define column dimensionsIndex[1]

#include <iostream>
#include "../../include/gamelogic/Board.h"

Board::Board(int sideSize): grid(sideSize)
{
	this->addRandomTile(2);
}

Board::~Board()
{}


void Board::updateGrid(bool slideDirection[2])
{
	if(slideDirection[0] != 0 || slideDirection[1] != 0){
		this->slideTiles(slideDirection);
		this->addRandomTile(2);
	}
}


std::vector<int> Board::getFreeCells()
{
	std::vector<int> freeCells;
	for (int i = 0; i < this->gridSize[0] * this->gridSize[1]; i++)
	{
		if (this->grid[i] == 0)
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
			this->grid[freeCells[randomFreeCellIndex]] = randomValue;
			freeCells.erase(freeCells.begin() + randomFreeCellIndex);
		}
		else {
			break;
		}
	}
	std::cout << std::endl;
}

void Board::mergeTiles(Tile* currentTile, Tile* targetTile) {
	currentTile->value += targetTile->value;
	targetTile->value = 0;
	Tile* tmpTile = targetTile;
	targetTile = currentTile;
	targetTile = tmpTile;
}

void Board::slideTiles(bool slideDirection[2])
{
	bool leftOrUpSlide = slideDirection[0];											//right/down : direction = 0			;	left/up : direction = 1
	bool rightOrDownSlide = !leftOrUpSlide;											//right/down : oppositeDirection = 1	;	left/up : oppositeDirection = 0
	int cursorOffsetDirection = leftOrUpSlide * -1 + rightOrDownSlide * 1;			//right/down : offset = 1				;	left/up : offset = -1
	
	bool axis = slideDirection[1];													//left/right : axis = 0					;	up/down : axis = 1
	bool oppositeAxis = !axis;														//left/right : oppositeAxis = 1			;	up/down : oppositeAxis = 0
	
	int dimensionsIndex[2]; //dimIndex[0] = row; dimIndex[1] = column				//axis = 0   : row = i ; col = j		;	axis = 1: row = j ; col = i 
	int gridSize[2] = { this->grid.getSingleSize(WIDTH), this->grid.getSingleSize(HEIGHT) };
	
	for (int i = 0; i < gridSize[axis]; i++) {
		dimensionsIndex[axis] = i;	//define the index of the column or row to slide
		for (int j = 1; j < gridSize[oppositeAxis]; j++) {
			dimensionsIndex[oppositeAxis] = (gridSize[oppositeAxis] - j - 1 ) * leftOrUpSlide + j * rightOrDownSlide;	//define the index of the column or row to slide
			this->grid(ROW, COL)->mergedAlready = false;
			if (this->grid(ROW, COL)->value != 0) {
				bool lockSlide = false;
				int slideOffset = 0;
				while(!lockSlide && slideOffset < this->grid.getSingleSize(axis)) {
					
					Tile* currentTile = this->grid(ROW, COL);
					Tile* slideTargetTile = this->grid(ROW - , COL - );
					if (slideTargetTile->value == 0 || (currentTile->value == slideTargetTile->value && !slideTargetTile->mergedAlready)) {
						this->mergeTiles(currentTile, slideTargetTile);
					}
					else {
						lockSlide = true;
					}
					ROW += cursorOffsetDirection * slideOffset * oppositeAxis;
					COL += cursorOffsetDirection * slideOffset * axis;
					++slideOffset;
					offsetRow += cursorOffsetDirection * slideOffset * oppositeAxis;
					offsetColumn += cursorOffsetDirection * slideOffset * axis;
				}				  
			}
		
		}
	}

}

/*while(this->grid[row * 4 + column].value != 0 && this->grid[row * 4 + column].stuck == 0)
				{
					if (virtualPose + 1 >= 4 * (row + 1)) {//if border
						if (virtualPose != row * 4 + column) {(virtualPose != row * 4 + column) { 
							this->grid[virtualPose].value = this->grid[row * 4 + column].value;
							this->grid[row * 4 + column].value = 0;
						}
						this->grid[virtualPose].stuck = 1;
					}
					else if (this->grid[virtualPose + 1].value == 0) {
						virtualPose ++;
					}
					else if (this->grid[virtualPose +1].value == this->grid[row * 4 + column].value && this->grid[virtualPose + 1].stuck != 2) {//fusion
						this->grid[virtualPose + 1].value *= 2;
						this->grid[row * 4 + column].value = 0;
						this->grid[virtualPose + 1].stuck = 2;
					}
					else {
							this->grid[virtualPose].value = this->grid[row * 4 + column].value;
							this->grid[row * 4 + column].value = 0;
						}
						this->grid[virtualPose].stuck = 1;
					}*/