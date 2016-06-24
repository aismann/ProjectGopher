#include "Game.h"

void Game::createWindow(){
  state = INITIALISATION;
  //
  //frame = 0;
  //fps = 0;
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
        if(displaySplash(window, getWidth(), getHight()) != true)
          state = SPLASHSCREEN;
        else state = MENU;
        break;
      }
      case gameState::MENU:{
        diaplayMenu(window, getWidth(), getHight());
        //window.close();
        //state = END;
        break;
      }
    }
  }
}

/*void Game::update(){
  if(clock.getElapsedTime().asSeconds() >= 1.f){
    fps = frame;
    frame = 0;
    clock.restart();
  }
  ++frame;
}*/
