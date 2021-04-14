#include "Grid.h"
#include <iostream>
#include <queue>

Grid::Grid(int _gridWidth, int _gridHeight, int _windowWidth, int _windowHeight)
{
    grid_width = _gridWidth;
    grid_height = _gridHeight;
    cell_width = (float)_windowWidth / _gridWidth;
    cell_height = (float)_windowHeight / _gridHeight;

    for (int y = 0; y < grid_height; y++)
    {
        for (int x = 0; x < grid_width; x++)
        {
            grid.push_back(Cell());
        }
    }
}
void Grid::UpdateNeighbours()
{
    for(int y = 0; y < grid_height; y++) 
    {
        for (int x = 0; x < grid_width; x++)
        {
            CalculateNeighbours(x, y);
        }
    }
}
void Grid::CalculateNeighbours(int x, int y)
{
    int n = 0;
    int w = grid_width;
    int h = grid_height;

    if (x + 1 < w) 
    {
        if (grid[grid_width * (x+1) + y].GetCurState() == 1)
        {
            n += 1;
        }
        if (y - 1 > 0) 
        {
            if(grid[grid_width * (x+1) + (y-1)].GetCurState() == 1)
            {
                n += 1;
            }
        }
       
    }
    
    if(y + 1 < h && x + 1 < w) 
    {
        if(grid[grid_width * (x+1) + (y+1)].GetCurState() == 1)
        {
            n += 1;
        }
    }
            
    if(x - 1 > 0) 
    {
        if(grid[grid_width * (x-1) + y].GetCurState() == 1)
        {
            n += 1;
        }

        if (y + 1 < h) 
        {
            if(grid[grid_width * (x-1) + (y+1)].GetCurState() == 1)
            {
                n += 1;
            }
        }

        if (y - 1 > 0)
        {
            if (grid[grid_width * (x-1) + (y-1)].GetCurState() == 1)
            {
                n += 1;
            }
        }
    }
  

    if(y + 1 < h) 
    {
        if(grid[grid_width * x + (y+1)].GetCurState() == 1)
        {
            n += 1;
        }
    }
    if(y - 1 > 0) 
    {
        if(grid[grid_width * x + (y-1)].GetCurState() == 1)
        {
            n += 1;
        }
    }
    
                      
    grid[grid_width * x + y].SetNeighbors(n);
}
std::queue<sf::RectangleShape> Grid::RenderGrid()
{
    std::queue<sf::RectangleShape> rects;
    for (int y = 0; y < grid_height; y++)
    {
        for (int x = 0; x < grid_width; x++)
        {
            Cell& cur_cell = grid[grid_width*x+y];
           
            if (cur_cell.GetCurState() == 1)
            {
                if (cur_cell.GetNeighbours() != 2 && cur_cell.GetNeighbours() != 3)
                {
                    cur_cell.SetCurState(0);
                }
            }
            else
            {
                if (cur_cell.GetNeighbours() == 3)
                {
                    cur_cell.SetCurState(1);
                }
            }



            if (cur_cell.GetCurState() == 1)
            {
                sf::RectangleShape tempRect(sf::Vector2f(cell_width, cell_height));
                tempRect.setOrigin(cell_width / 2, cell_height / 2);
                tempRect.setFillColor(rand() % 50 < 20 ? sf::Color::White : sf::Color::White);
                tempRect.setPosition(cell_width * x, cell_height * y);

                rects.push(tempRect);
            }
        }
    }
    return rects;
}