#include "Game.h"

void Game::createWindow(){
  state = INITIALISATION;
  RenderWindow window(VideoMode(getWidth(), getHight()), "NAME");
  RenderWindow * pointer;
  pointer = &window;
  while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
}
