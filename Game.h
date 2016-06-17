#include "Initialisation.h"
#include "Menu.h"

using namespace std;
using namespace sf;

class Game: public Initialisation, public Menu{
  private:

  protected:
    enum gameState {INITIALISATION, MENU, END};
    gameState state;

  public:
    void createWindow();
    void createMainLoop(RenderWindow&);

};
