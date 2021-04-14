#include "Cell.h"
#include <stdlib.h>

void Cell::SetCurState(int val)
{
	curState = val;
}

void Cell::SetNeighbors(int amount)
{
	neighbours = amount;
}

void Cell::SetPosition(sf::Vector2i pos)
{
	position = pos;
}

Cell::Cell()
{
	curState = rand() % 2;
	neighbours = 0;
}

Cell::Cell(int state)
{
	curState = state;
	neighbours = 0;
}
