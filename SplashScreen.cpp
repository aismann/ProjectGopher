#include "SplashScreen.h"

/*void SplashScreen::loadSfmlLogoTexture(){
  if(!sfmlLogoTexture.loadFromFile(sfmlLogoLocation, IntRect(0, 0, LOGO_WIDTH, LOGO_HIGHT))){
    //err..
  }
  sfmlLogoTexture.setSmooth(true);
  sfmlLogoTexture.setRepeated(false);
}

void SplashScreen::loadSfmlLogoSprite(){
  sfmlLogoSprite.setTexture(sfmlLogoTexture);
}

void SplashScreen::openSplashScreen(RenderWindow &window, int width, int hight){
  loadSfmlLogoTexture();
  loadSfmlLogoSprite();
  sfmlLogoSprite.setPosition(LogoWidth(width), LogoHight(hight));
  window.clear();
  window.draw(sfmlLogoSprite);
  window.display();
}

int SplashScreen::LogoWidth(int width){
  return width/2 - LOGO_WIDTH/2;
}

int SplashScreen::LogoHight(int hight){
  return hight/2 - LOGO_HIGHT/2;
}*/

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
  title.setString("Project::Gopher");
  title.setCharacterSize(50);
  title.setPosition(centerWidth(width) - title.getGlobalBounds().width/2, centerHight(hight));
  title.setColor(Color::White);
  return title;
}

Text SplashScreen::setPressKey(int width, int hight){
  Text pressKey;
  pressKey.setFont(font);
  pressKey.setString("press any key..");
  pressKey.setCharacterSize(20);
  pressKey.setPosition(centerWidth(width) - pressKey.getGlobalBounds().width/2, centerHight(hight) + 283);
  pressKey.setColor(Color::White);
  return pressKey;
}
