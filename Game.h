#include "Options.h"
#include "MainMenu.h"
#include "Splash.h"

class Game: public Initialisation,
            public Splash{
private:
  Menu * menu;
  Menu * options;
protected:
  enum gameState {INITIALISATION, MENU, END, SPLASHSCREEN, OPTIONS, NEW_GAME, CONTINUE};
  gameState state;

public:
  Game();
  void createWindow();
  void createMainLoop(RenderWindow&);
  void endingEvent(RenderWindow&);
};
