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
  Font font;
  const string fontLocation = "data/font/font.ttf";
  const string titleString = "Project::Gopher";
  const string pressKeyString = "press any key..";

protected:

public:
  void loadFont();
  int centerWidth(int);
  int centerHight(int);
  void displaySplash(RenderWindow&, int, int);
  Text setTitle(int, int);
  Text setPressKey(int, int);
};
