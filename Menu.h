#ifndef MENU_H
#define MENU_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

class Menu{
private:
  const string fontLocation = "data/font/font.ttf";

protected:
  Font font;

public:
  virtual int displayMenu(RenderWindow&, int, int) = 0;
  virtual int EventHandeler(RenderWindow&) = 0;
  virtual int verticalPosition(int) = 0;
  virtual int horisontalPosition(int) = 0;
  virtual void highlight(RenderWindow&) = 0;
  virtual void setFonts(RenderWindow&, int, int) = 0;
  Vector2i getMousePosition(RenderWindow&);
  void loadFont();
};

#endif
