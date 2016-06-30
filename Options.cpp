#include "Options.h"

int Options::displayOptions(RenderWindow &window, int width, int height){
  setOptionsFonts(window, width, height);
  window.clear(Color(25, 25, 25));
  for(int i = 0; i < 9; i++){
    window.draw(optionsText[i]);
  }
  window.display();
  //return menuListener(window);
  return 0;
}

void Options::setOptionsFonts(RenderWindow &window, int width, int height){
  for(int i = 0; i < 9; i++){
    optionsText[i].setFont(optionsFont);
    optionsText[i].setCharacterSize(20);
    optionsText[i].setString(optionsString[i]);
    optionsText[i].setPosition((optionsWidth(width) - optionsText[i].getGlobalBounds().width/2), (optionsHeight(height) + i * 30));
    optionsHighlight(window);
  }
}

int Options::optionsWidth(int width){
  return width/2;
}

int Options::optionsHeight(int height){
  return height/2;
}

Vector2i Options::getMousePosition(RenderWindow &window){
  window.setMouseCursorVisible(true);
  Vector2i mouse = Mouse::getPosition( window );
  return mouse;
}

void Options::optionsHighlight(RenderWindow &window){
  for(int i = 0; i < 9; i++){
    if(optionsText[i].getGlobalBounds().contains( static_cast <Vector2f> (getMousePosition(window))))
      optionsText[i].setColor(Color::White);
    else optionsText[i].setColor(Color(224, 246, 207));
  }
}

int Options::optionsListener(RenderWindow &window){
  return 0;
}
