#include "Menu.h"

bool Menu::diaplayMenu(RenderWindow &window, int width, int height){
  Text menuText[4];
  const array<string, 4> menuStrings = { {"NEW GAME", "CONTINUE", "OPTIONS", "END"} };
  for(int i = 0; i < menuStrings.size(); i++){
    menuText[i].setFont(font);
    menuText[i].setCharacterSize(40);
    menuText[i].setString(menuStrings[i]);
    menuText[i].setPosition(4*(1024/5) - menuText[i].getGlobalBounds().width, 300 + i * 40);
  }
  window.clear();
  for(int i = 0; i < menuStrings.size(); i++)
    window.draw(menuText[i]);
    window.display();
  return true;
}


int Menu::menuEvent(RenderWindow&){
  return 0;
}


int Menu::width(int width){
  return width/2;
}

int Menu::height(int height){
  return height/2;
}
