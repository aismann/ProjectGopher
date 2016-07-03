#include "Splash.h"

bool Splash::displaySplash(RenderWindow &window, int width, int hight){
  window.draw(setPressKey(width, hight));
  window.draw(setTitle(width, hight));
  window.draw(setLogo(width, hight));
  window.display();
  window.clear(Color(25, 25, 25));
  return eventHandeler(window);
}

bool Splash::eventHandeler(RenderWindow &window){
  Event event;
  if(window.pollEvent(event) == true){
    if(event.type == Event::KeyPressed ||
       event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) return true;
  }
  return false;
}

void Splash::loadLogoTexture(){
  if(!LogoTexture.loadFromFile(LogoLocation, IntRect(0, 0, 256, 256))){
    //err..
  }
  LogoTexture.setSmooth(true);
  LogoTexture.setRepeated(false);
}

void Splash::loadLogoSprite(){
  LogoSprite.setTexture(LogoTexture);
}

Sprite Splash::setLogo(int width, int hight){
  loadLogoTexture();
  loadLogoSprite();
  LogoSprite.setPosition(LogoWidth(width), LogoHight(hight));
  return LogoSprite;
}

int Splash::LogoWidth(int width){
  return width/2 - 128;
}

int Splash::LogoHight(int hight){
  return hight/2 - 200;
}

void Splash::loadFont(){
  if(!SplashFont.loadFromFile(fontLocation)){
    //err
  }
}

Font Splash::getFont(){
  return SplashFont;
}

int Splash::centerWidth(int width){
  return width/2;
}

int Splash::centerHight(int hight){
  return hight/2;
}

Text Splash::setTitle(int width, int hight){
  Splash::loadFont();
  Text title;
  title.setFont(SplashFont);
  title.setString(titleString);
  title.setCharacterSize(50);
  title.setPosition(centerWidth(width) - title.getGlobalBounds().width/2, centerHight(hight));
  title.setColor(Color(224, 246, 207));
  return title;
}

Text Splash::setPressKey(int width, int hight){
  Text pressKey;
  pressKey.setFont(SplashFont);
  pressKey.setString(pressKeyString);
  pressKey.setCharacterSize(20);
  pressKey.setPosition(centerWidth(width) - pressKey.getGlobalBounds().width/2, centerHight(hight) + 283);
  pressKey.setColor(Color(224, 246, 207));
  return pressKey;
}

/*Text SplashScreen::action(int width, int hight){
  Text action;
  action.setFont(SplashFont);
  action.setString("KEY PRESSED!");
  action.setCharacterSize(20);
  action.setPosition(centerWidth(width) - action.getGlobalBounds().width/2, centerHight(hight) + 183);
  action.setColor(Color::White);
  return action;
}*/
