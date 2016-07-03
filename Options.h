#include "Menu.h"
#include "Initialisation.h"

using namespace std;
using namespace sf;

class Options: public virtual Menu{
private:
  Initialisation initialisation;
  int volumeFX;
  int volumeAudio;
  Text optionsText[17];
  string keyBinds[6];
  string optionsString[10] = {"RESOLUTION:   ",
                              "AUDIO FX:     ",
                              "AUDIO MUSIC:  ",
                              "UP:           ",
                              "DOWN:         ",
                              "LEFT:         ",
                              "RIGHT:        ",
                              "FIRE:         ",
                              "SHIELD:       ",
                              "APPLY"};
  string resolutionString[4] = {"1366x768",
                                "1360x768",
                                "1024x768",
                                "800x600"};
  string optionsParse[9];
  int keybindValue;
  string pressKeyPopUp = "Press key";

protected:
  enum optionState {RESOLUTION, AUDIO_FX, AUDIO_MUSIC, KEYBINDS, OPTIONS, RETURN};
  optionState state;
public:
  Options();
  virtual int displayMenu(RenderWindow&, int, int);
  void displayOptions(RenderWindow&, int, int);
  void displayResolution(RenderWindow&, int, int);
  void displayAudioFX(RenderWindow&, int, int);
  void displayAudioMusic(RenderWindow&, int, int);
  void displayKeyBinds(RenderWindow&);
  virtual int EventHandeler(RenderWindow&);
  virtual int verticalPosition(int);
  virtual int horisontalPosition(int);
  virtual void highlight(RenderWindow&);
  virtual void setFonts(RenderWindow&, int, int);
  void getParse();
  string getKey(RenderWindow&);
};
