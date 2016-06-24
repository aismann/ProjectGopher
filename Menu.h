#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <array>
#include "SplashScreen.h"

using namespace std;
using namespace sf;

class Menu: public SplashScreen{
  private:
    //const string content[4] {"NEW GAME", "CONTINUE", "OPTIONS", "END"};
  protected:
    enum menuState {END, OPTIONS, CONTINUE, NEW_GAME};

  public:
    bool diaplayMenu(RenderWindow&, int, int);
    int menuEvent(RenderWindow&);
    int width(int);
    int height(int);

};
