#include "MainMenu.h"

MainMenu::MainMenu(){
  loadFont();
}

int MainMenu::displayMenu(RenderWindow &window, int width, int height){
  setFonts(window, width, height);
  window.clear(Color(25, 25, 25));
  for(int i = 0; i < 4; i++){
    window.draw(menuText[i]);
  }
  window.display();
  return EventHandeler(window);
}

int MainMenu::EventHandeler(RenderWindow &window){
  Event event;
  while(window.pollEvent(event)){
    if(menuText[0].getGlobalBounds().contains(static_cast <Vector2f> (getMousePosition(window)))
    && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
      return 1;
    else if(menuText[1].getGlobalBounds().contains(static_cast <Vector2f> (getMousePosition(window)))
    && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
      return 2;
    else if(menuText[2].getGlobalBounds().contains(static_cast <Vector2f> (getMousePosition(window)))
    && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
      return 3;
    else if(menuText[3].getGlobalBounds().contains(static_cast <Vector2f> (getMousePosition(window)))
    && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
      return 4;
  }
}

int MainMenu::verticalPosition(int height){
  return height/2;
}

int MainMenu::horisontalPosition(int width){
  return width/2;
}

void MainMenu::highlight(RenderWindow &window){
  for(int i = 0; i < 4; i++){
    if(menuText[i].getGlobalBounds().contains( static_cast <Vector2f> (getMousePosition(window))))
      menuText[i].setColor(Color::White);
    else menuText[i].setColor(Color(224, 246, 207));
  }
}

void MainMenu::setFonts(RenderWindow &window, int width, int height){
  for(int i = 0; i < 4; i++){
    menuText[i].setFont(font);
    menuText[i].setCharacterSize(20);
    menuText[i].setString(menuString[i]);
    menuText[i].setPosition((horisontalPosition(width) - menuText[i].getGlobalBounds().width/2), (verticalPosition(height) + i * 30));
    highlight(window);
  }
}
