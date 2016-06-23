#include "SplashScreen.h"

bool SplashScreen::displaySplash(RenderWindow &window, int width, int hight){
  window.draw(setPressKey(width, hight));
  window.draw(setTitle(width, hight));
  window.draw(setLogo(width, hight));
  window.display();
  window.clear(Color(25, 25, 25));
  return eventHandeler(window);
}

bool SplashScreen::eventHandeler(RenderWindow &window){
  Event event;
  if(window.pollEvent(event) == true){
    if(event.type == Event::KeyPressed) return true;
    else return false;
  }
}

void SplashScreen::loadLogoTexture(){
  if(!LogoTexture.loadFromFile(LogoLocation, IntRect(0, 0, 256, 256))){
    //err..
  }
  LogoTexture.setSmooth(true);
  LogoTexture.setRepeated(false);
}

void SplashScreen::loadLogoSprite(){
  LogoSprite.setTexture(LogoTexture);
}

Sprite SplashScreen::setLogo(int width, int hight){
  loadLogoTexture();
  loadLogoSprite();
  LogoSprite.setPosition(LogoWidth(width), LogoHight(hight));
  return LogoSprite;
}

int SplashScreen::LogoWidth(int width){
  return width/2 - 128;
}

int SplashScreen::LogoHight(int hight){
  return hight/2 - 200;
}

void SplashScreen::loadFont(){
  if(!font.loadFromFile(fontLocation)){
    //err
  }
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
  title.setColor(Color(224, 246, 207));
  return title;
}

Text SplashScreen::setPressKey(int width, int hight){
  Text pressKey;
  pressKey.setFont(font);
  pressKey.setString(pressKeyString);
  pressKey.setCharacterSize(20);
  pressKey.setPosition(centerWidth(width) - pressKey.getGlobalBounds().width/2, centerHight(hight) + 283);
  pressKey.setColor(Color(224, 246, 207));
  return pressKey;
}

Text SplashScreen::action(int width, int hight){
  Text action;
  action.setFont(font);
  action.setString("KEY PRESSED!");
  action.setCharacterSize(20);
  action.setPosition(centerWidth(width) - action.getGlobalBounds().width/2, centerHight(hight) + 183);
  action.setColor(Color::White);
  return action;
}
