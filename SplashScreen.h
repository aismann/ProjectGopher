#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

class SplashScreen{
private:
  Texture sfmlLogoTexture;
  Sprite sfmlLogoSprite;
  string sfmlLogoLocation = "data/graphics/SplashScreen/sfml-logo-small.png";

protected:
  const int LOGO_WIDTH = 373;
  const int LOGO_HIGHT = 113;
public:
  void openSplashScreen(RenderWindow&, int, int);
  void loadSfmlLogoTexture();
  void loadSfmlLogoSprite();
  int LogoWidth(int);
  int LogoHight(int);
};
