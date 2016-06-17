#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

using namespace std;
using namespace sf;

class Menu{
  private:
    Font font;

  protected:
    enum menuState {MENU, OPTIONS, NEW_GAME};

  public:
    void openMenu();
    void openOptions();

};
