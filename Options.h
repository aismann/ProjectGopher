#include "Menu.h"

using namespace std;
using namespace sf;

class Options{
  private:
    Text optionsText[9];
    string optionsString[9] = {"RESOLUTION",
                               "AUDIO FX",
                               "AUDIO MUSIC",
                               "UP",
                               "DOWN",
                               "LEFT",
                               "RIGHT",
                               "FIRE",
                               "SHIELD"};
    string resolutionString[4] = {"1366x768",
                                  "1360x768",
                                  "1024x768",
                                  "800x600"};
    int volumeFX;
    int volumeAudio;
    string keyBinds[6];
  protected:

  public:
    int displayOptions(RenderWindow&, int, int);
    void setOptionsFonts(RenderWindow&, int, int);
    int optionsWidth(int);
    int optionsHeight(int);
    //Vector2i getMousePosition(RenderWindow&);
    void optionsHighlight(RenderWindow&);
    int optionsListener(RenderWindow&);

};
