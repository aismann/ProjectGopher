#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "data/lib/pugixml/pugixml.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

using namespace std;
using namespace pugi;

class Initialisation{
private:
  //graphics fields
  int width;
  int hight;
  string mode;
  //audio fields
  int volumeFX;
  int volumeMusic;
  //keyBinds fields
  string upKey;
  string downKey;
  string leftKey;
  string rightKey;
  string fireKey;
  string shieldKey;

protected:

public:
  //load config xml file and set class fields
  void loadConfig();
  //save current class fields to xml config file
  void saveConfig();
  //load default config
  void loadDefaultConfig();
  //test
  void test();
  //graphics setters & getters
  int getWidth();
  void setWidth(int newWidth);
  int getHight();
  void setHight(int newHight);
  string getMode();
  void setMode(string newMode);
  //audio setters & getters
  int getVolumeFX();
  void setVolumeFX(int newVolumeFX);
  int getVolumeMusic();
  void setVolumeMusic(int newVolumeMusic);
  //keyBinds setters & getters
  string getUpKey();
  void setUpKey(string newUp);
  string getDownKey();
  void setDownKey(string newDown);
  string getLeftKey();
  void setLeftKey(string newLeft);
  string getRightKey();
  void setRightKey(string newRight);
  string getFireKey();
  void setFireKey(string newFire);
  string getShieldKey();
  void setShieldKey(string newShield);
};
