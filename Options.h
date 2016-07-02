#include "Menu.h"
#include "Initialisation.h"

using namespace std;
using namespace sf;

class Options: public virtual Menu{
private:
  Initialisation initialisation;
  int volumeFX;
  int volumeAudio;
  Text optionsText[9];
  string keyBinds[6];
  string optionsString[9] = {"RESOLUTION:  ",
                             "AUDIO FX:    ",
                             "AUDIO MUSIC: ",
                             "UP:          ",
                             "DOWN:        ",
                             "LEFT:        ",
                             "RIGHT:       ",
                             "FIRE:        ",
                             "SHIELD:      "};
  string resolutionString[4] = {"1366x768",
                                "1360x768",
                                "1024x768",
                                "800x600"};
  string optionsParse[9];

protected:

public:
  Options();
  virtual int displayMenu(RenderWindow&, int, int);
  virtual int EventHandeler(RenderWindow&);
  virtual int verticalPosition(int);
  virtual int horisontalPosition(int);
  virtual void highlight(RenderWindow&);
  virtual void setFonts(RenderWindow&, int, int);
  void getParse();
};
