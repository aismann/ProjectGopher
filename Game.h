#include "Initialisation.h"
#include "Menu.h"

using namespace std;
using namespace sf;

class Game: public Initialisation,
            public Menu{
  private:
    Clock clock;
    unsigned int frame;
    unsigned int fps;

  protected:
    enum gameState {INITIALISATION, MENU, END, SPLASHSCREEN, OPTIONS, NEW_GAME, CONTINUE};
    gameState state;

  public:
    void createWindow();
    void createMainLoop(RenderWindow&);
    void update();

};
