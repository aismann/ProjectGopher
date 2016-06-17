#include "Initialisation.h"

using namespace std;
using namespace sf;

class Game: public Initialisation{
  private:

  protected:
    enum gameState {INITIALISATION, MENU, END};
    gameState state;

  public:
    void createWindow();

};
