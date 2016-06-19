#include "Initialisation.h"
#include "Menu.h"
#include "SplashScreen.h"

using namespace std;
using namespace sf;

class Game: public Initialisation,
            public Menu,
            public SplashScreen{
  private:
    Clock clock;
    unsigned int frame;
    unsigned int fps;
    
  protected:
    enum gameState {INITIALISATION, MENU, END, SPLASHSCREEN};
    gameState state;

  public:
    void createWindow();
    void createMainLoop(RenderWindow&);
    void update();

};
