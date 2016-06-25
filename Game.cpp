 #include "Game.h"

void Game::createWindow(){
  state = INITIALISATION;
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
        switch(displayMenu(window, getWidth(), getHight())){
          case 1:{
            state = NEW_GAME;
            break;
          }
          case 2:{
            state = CONTINUE;
            break;
          }
          case 3:{
            state = OPTIONS;
            break;
          }
          case 4:{
            state = END;
            break;
          }
          case 0:{
            state = MENU;
            break;
          }
        }
        break;
      }
      case gameState::NEW_GAME:{
        window.close();
        state = END;
        break;
      }
      case gameState::CONTINUE:{
        window.close();
        state = END;
        break;
      }
      case gameState::OPTIONS:{
        window.close();
        state = END;
        break;
      }
      case gameState::END:{
        window.close();
        state = END;
        break;
      }
    }
  }
}
