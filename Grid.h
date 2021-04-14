#pragma once
#include "Cell.h"
#include "SFML/Graphics.hpp"
#include <queue>

class Grid {
private:
    int grid_width;
    int grid_height;
    float cell_width;
    float cell_height;
    std::vector<Cell> grid;
    void CalculateNeighbours(int x, int y);
public:
    void UpdateNeighbours();
    std::queue<sf::RectangleShape> RenderGrid();
    Grid(int _gridWidth, int _gridHeight, int _windowWidth, int _windowHeight);
};
