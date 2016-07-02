#include "Menu.h"

Vector2i Menu::getMousePosition(RenderWindow &window){
  window.setMouseCursorVisible(true);
  Vector2i mouse = Mouse::getPosition( window );
  return mouse;
}

void Menu::loadFont(){
  if(!font.loadFromFile(fontLocation)){
    //err
  }
}
