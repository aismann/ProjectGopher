#include "Game.h"

void Game::createWindow(){
  state = INITIALISATION;
  //
  frame = 0;
  fps = 0;
  //
  RenderWindow window(VideoMode(getWidth(), getHight()), "ProjectGopher");
  RenderWindow * pointer;
  pointer = &window;
  state = SPLASHSCREEN;
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
    switch(state){
      case gameState::SPLASHSCREEN:{
          openSplashScreen(window, getWidth(), getHight());
        break;
      }
      case gameState::MENU:{

        break;
      }
    }
  }
}

void Game::update(){
  if(clock.getElapsedTime().asSeconds() >= 1.f){
    fps = frame;
    frame = 0;
    clock.restart();
  }
  ++frame;
}
