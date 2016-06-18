#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

using namespace std;
using namespace sf;

class SplashScreen{
private:
  Texture sfmlLogoTexture;
  Sprite sfmlLogoSprite;

protected:

public:
  void openSplashScreen();
};
