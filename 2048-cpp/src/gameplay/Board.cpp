#include <iostream>
#include <stdlib.h>

#include "../../include/gamelogic/Board.h"

Board::Board(int sideSize)
{
	this->gridSize[0] = sideSize;
	this->gridSize[1] = sideSize;
	this->generateGrid(gridSize);
}

Board::~Board()
{}

int Board::getGridLength(GridDimension lengthIndex)
{
	return this->gridSize[lengthIndex];
}


void Board::updateGrid(int slideDirection[2])
{
	if(slideDirection[0] != 0 || slideDirection[1] != 0){
		this->slideTiles(slideDirection);
		this->addRandomTile(1);
	}
	
}

void Board::generateGrid(int gridSize[2])
{
	this->grid.resize(gridSize[0] * gridSize[1]);
	for (int i = 0; i < gridSize[0] * gridSize[1]; i++)
	{
		this->grid[i] = (Tile*)malloc(sizeof Tile);
		this->grid[i]->value = 0;
	}
	this->addRandomTile(2);
}

std::vector<int> Board::getFreeCells()
{
	std::vector<int> freeCells;
	for (int i = 0; i < this->gridSize[0] * this->gridSize[1]; i++)
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
			freeCells.erase(freeCells.begin() + randomFreeCellIndex);
		}
		else {
			break;
		}
	}
	std::cout << std::endl;
}

void Board::slideTiles(int slideDirection[2])
{
	int direction = slideDirection[0];
	int axis = slideDirection[1];
	int oppositeAxis = 1 - axis;
	int hasNegativeDirection = direction == -1 ? 1 : 0;

	int dimensionsIndexes[2];
	for (int i = 0; i < this->gridSize[axis]; i++) {
		dimensionsIndexes[axis] = i; //if orientation = 1 (vertical slide), int i will be the column index in lines
		for (int j = 1; j < this->gridSize[oppositeAxis]; j++) {
			dimensionsIndexes[oppositeAxis] = (this->gridSize[oppositeAxis] - j - 1 ) * (1 - hasNegativeDirection) + j * hasNegativeDirection; //if direction is 
			int cursor = dimensionsIndexes[0] * this->gridSize[0] + dimensionsIndexes[1];
			int cursorRed = (dimensionsIndexes[0] + ( direction * axis)) * this->gridSize[0] + dimensionsIndexes[1] + (direction * oppositeAxis);
			if (this->grid[cursor]->value != 0) {
				//while (this->grid[cursor].value != 0 && this->grid[cursor].stuck == 0)
				{
					if (this->grid[cursorRed]->value == 0) {
						this->grid[cursorRed]->value = this->grid[cursor]->value;
						this->grid[cursor]->value = 0;
					}
					else if (this->grid[cursorRed]->value == this->grid[cursor]->value) {
						this->grid[cursorRed]->value = this->grid[cursorRed]->value * 2;
						this->grid[cursor]->value = 0;
					}
				}
			}
		
		}
	}

}

/*
void Board::slideTiles(int slideDirection[2])
{
	int virtualPose = 0;
	for (int row = 0; row < 4; row++) {
		for (int column = 3; column >= 0; column--) {
			if (this->grid[row * 4 + column].value != 0) {
				virtualPose = row * 4 + column;
				while(this->grid[row * 4 + column].value != 0 && this->grid[row * 4 + column].stuck == 0)
				{
					if (virtualPose + 1 >= 4 * (row + 1)) {//if border
						if 
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
					}
				}
			}
		}
	}
	for (int row = 0; row < 4; row++) {
		for (int column = 3; column >= 0; column--) {
			this->grid[row * 4 + column].stuck = 0;
		}
	}
}*/