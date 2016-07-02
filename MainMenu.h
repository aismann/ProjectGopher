#include "Menu.h"

//using namespace std;
//using namespace sf;

class MainMenu: public virtual Menu{
private:
  Text menuText[4];
  string menuString[4] = {"NEW GAME",
                          "HIGH SCORE",
                          "OPTIONS",
                          "EXIT"};

protected:

public:
  MainMenu();
  virtual int displayMenu(RenderWindow&, int, int);
  virtual int EventHandeler(RenderWindow&);
  virtual int verticalPosition(int);
  virtual int horisontalPosition(int);
  virtual void highlight(RenderWindow&);
  virtual void setFonts(RenderWindow&, int, int);
};
