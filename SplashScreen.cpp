#include "SplashScreen.h"

void SplashScreen::loadSfmlLogoTexture(){
  if(!sfmlLogoTexture.loadFromFile(sfmlLogoLocation, IntRect(0, 0, LOGO_WIDTH, LOGO_HIGHT))){
    //err..
    cout << "Logo image problem" << endl;
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
}
