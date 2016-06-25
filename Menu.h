#include <array>
#include "SplashScreen.h"

using namespace std;
using namespace sf;

class Menu: public SplashScreen{
  private:
    Text menuText[4];
    string menuString[4] = {"NEW GAME", "CONTINUE", "OPTIONS", "EXIT"};
  protected:

  public:
    int displayMenu(RenderWindow&, int, int);
    void setFonts(RenderWindow&, int, int);
    int menuWidth(int);
    int menuHeight(int);
    Vector2i getMousePosition(RenderWindow&);
    void highlight(RenderWindow&);
    int menuListener(RenderWindow&);

};
