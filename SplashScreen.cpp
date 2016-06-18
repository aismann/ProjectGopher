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

void SplashScreen::openSplashScreen(RenderWindow &window){
  loadSfmlLogoTexture();
  loadSfmlLogoSprite();
  sfmlLogoSprite.setPosition(400 - 170, 300 - 120);
  window.clear();
  window.draw(sfmlLogoSprite);
  window.display();
}

Sprite SplashScreen::getSfmlLogoSprite(){
  return sfmlLogoSprite;
}
