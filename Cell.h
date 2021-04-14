#pragma once
#include <SFML/Graphics.hpp>
class Cell {
private:
	int neighbours;
	int curState;
	sf::Vector2i position;
public:
	inline int GetCurState() { return curState; }
	void SetCurState(int val);
	inline int GetNeighbours() { return neighbours; }
	void SetNeighbors(int amount);
	inline sf::Vector2i GetPosition() { return position; }
	void SetPosition(sf::Vector2i pos);
	Cell();
	Cell(int state);
};