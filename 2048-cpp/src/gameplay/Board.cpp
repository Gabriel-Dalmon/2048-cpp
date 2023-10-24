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


void Board::updateGrid(int slideDirection[2])
{
	this->addRandomTile(2);
	
}



void Board::generateGrid(int gridSize[2])
{
	this->grid.resize(gridSize[0] * gridSize[1]);
	for (int i = 0; i < gridSize[0] * gridSize[1]; i++)
	{
		this->grid[i] = 0;
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

void Board::slideTiles(int slideDirection[2])
{

}