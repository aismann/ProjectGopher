#include "SplashScreen.h"

void SplashScreen::loadFont(){
  if(!font.loadFromFile(fontLocation)){
    //err
  }
}

void SplashScreen::displaySplash(RenderWindow &window, int width, int hight){
  window.clear();
  window.draw(setTitle(width, hight));
  window.draw(setPressKey(width, hight));
  window.display();
}

int SplashScreen::centerWidth(int width){
  return width/2;
}

int SplashScreen::centerHight(int hight){
  return hight/2;
}

Text SplashScreen::setTitle(int width, int hight){
  SplashScreen::loadFont();
  Text title;
  title.setFont(font);
  title.setString(titleString);
  title.setCharacterSize(50);
  title.setPosition(centerWidth(width) - title.getGlobalBounds().width/2, centerHight(hight));
  title.setColor(Color::White);
  return title;
}

Text SplashScreen::setPressKey(int width, int hight){
  Text pressKey;
  pressKey.setFont(font);
  pressKey.setString(pressKeyString);
  pressKey.setCharacterSize(20);
  pressKey.setPosition(centerWidth(width) - pressKey.getGlobalBounds().width/2, centerHight(hight) + 283);
  pressKey.setColor(Color::White);
  return pressKey;
}
