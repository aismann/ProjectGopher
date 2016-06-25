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
  Texture LogoTexture;
  Sprite LogoSprite;

  const string LogoLocation = "data/graphics/SplashScreen/logo.png";
  const string fontLocation = "data/font/font.ttf";
  const string titleString = "Project::Gopher";
  const string pressKeyString = "press any key..";

protected:
    Font font;

public:
  bool displaySplash(RenderWindow&, int, int);
  bool eventHandeler(RenderWindow&);

  Sprite setLogo(int, int);
  void loadLogoTexture();
  void loadLogoSprite();
  int LogoWidth(int);
  int LogoHight(int);

  void loadFont();
  int centerWidth(int);
  int centerHight(int);
  Text setTitle(int, int);
  Text setPressKey(int, int);
  Text action(int, int);

  Font getFont();
};
