#include <SFML/Graphics.hpp>
#include <queue>
#include <future>

#include "Cell.h"
#include "Main.h"
#include "Grid.h"
#include <iostream>


const int SCREEN_WIDTH = 750;
const int SCREEN_HEIGHT = 750;

static sf::Color randColor()
{
    return sf::Color(rand() % 256, rand() % 256, rand() % 256);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Conway's game of life!", sf::Style::Titlebar);
    window.setFramerateLimit(60);

    std::queue<sf::RectangleShape> renderingQueue;

    Grid cellGrid(250,250,SCREEN_WIDTH,SCREEN_HEIGHT);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
           
        cellGrid.UpdateNeighbours();
        renderingQueue = cellGrid.RenderGrid();

        while (!renderingQueue.empty())
        {
            window.draw(renderingQueue.front());
            renderingQueue.pop();
        }

        window.display();
    }

    return 0;
}


