#include <iostream>

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


void Board::updateGrid(int slideDirection)
{
	this->slideTiles(slideDirection);
	this->addRandomTile(1);
	
}



void Board::generateGrid(int gridSize[2])
{
	this->grid.resize(gridSize[0] * gridSize[1]);
	for (int i = 0; i < gridSize[0] * gridSize[1]; i++)
	{
		this->grid[i].value = 0;
	}
	this->addRandomTile(2);
}

std::vector<int> Board::getFreeCells()
{
	std::vector<int> freeCells;
	for (int i = 0; i < this->gridSize[0] * this->gridSize[1]; i++)
	{
		if (this->grid[i].value == 0)
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
			this->grid[freeCells[randomFreeCellIndex]].value = randomValue;
			freeCells.erase(freeCells.begin() + randomFreeCellIndex);
		}
		else {
			break;
		}
	}
	std::cout << std::endl;
}

void Board::slideTiles(int slideDirection)
{
	switch (slideDirection) {
	case 1: //up
		for (int column = 0; column < 4; column++) {
			for (int row = 1; row <= 3; row++) {
				if (this->grid[row * 4 + column].value != 0) {
					if(this->grid[(row - 1) * 4 + column].value == 0) {
						this->grid[(row - 1) * 4 + column] = this->grid[row * 4 + column];
						this->grid[row * 4 + column].value = 0;
					}
					else if (this->grid[(row - 1) * 4 + column].value == this->grid[row * 4 + column].value) {//fusion
						this->grid[(row - 1) * 4 + column].value *= 2;
						this->grid[row * 4 + column].value = 0;
					}
				}
			}
		}
		break;

	case 2: //left
		for (int row = 0; row < 4; row++) {
			for (int column = 1; column <= 3; column++) {
				if (this->grid[row * 4 + column].value != 0) {
					if(this->grid[row * 4 + column - 1].value == 0) {
						this->grid[row * 4 + column - 1] = this->grid[row * 4 + column];
						this->grid[row * 4 + column].value = 0;
					}
					else if (this->grid[row * 4 + column - 1].value == grid[row * 4 + column].value) {//fusion
						this->grid[row * 4 + column - 1].value *= 2;
						this->grid[row * 4 + column].value = 0;
					}
				}
			}
		}
		break;

	case 3: //right
		for (int row = 0; row < 4; row++) {
			for (int column = 2; column >= 0; column--) {
				if (this->grid[row * 4 + column].value != 0) {
					if(this->grid[row * 4 + column + 1].value == 0) {
						this->grid[row * 4 + column + 1] = this->grid[row * 4 + column];
						this->grid[row * 4 + column].value = 0;
					}
					else if (this->grid[row * 4 + column + 1].value == this->grid[row * 4 + column].value) {//fusion
						this->grid[row * 4 + column + 1].value *= 2;
						this->grid[row * 4 + column].value = 0;
					}
				}
			}
		}
		break;

	case 4: //down
		for (int column = 0; column < 4; column++) {
			for (int row = 2; row >= 0; row--) {
				if (this->grid[row * 4 + column].value != 0) {
					if(this->grid[(row + 1) * 4 + column].value == 0) {
						this->grid[(row + 1) * 4 + column].value = this->grid[row * 4 + column].value;
						this->grid[row * 4 + column].value = 0;
					}
					else if(this->grid[(row + 1) * 4 + column].value == this->grid[row * 4 + column].value){ //fusion
						this->grid[(row + 1) * 4 + column].value *= 2;
						this->grid[row * 4 + column].value = 0;
					}
				}
			}
		}
		break;
	}
}