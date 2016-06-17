#include "Game.h"

void Game::createWindow(){
  state = INITIALISATION;
  RenderWindow window(VideoMode(getWidth(), getHight()), "NAME");
  RenderWindow * pointer;
  pointer = &window;
  createMainLoop(*pointer);
}

void Game::createMainLoop(RenderWindow &window){
  while(state != END){
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed){
          window.close();
          state = END;
        }
    }

    window.clear();
    window.display();
  }
}
