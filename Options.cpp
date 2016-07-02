#include "Options.h"

Options::Options(){
  loadFont();
}

int Options::displayMenu(RenderWindow &window, int width, int height){
  setFonts(window, width, height);
  window.clear(Color(25, 25, 25));
  for(int i = 0; i < 9; i++){
    window.draw(optionsText[i]);
  }
  window.display();
  //return EventHandeler(window);
  return 0;
}

int Options::EventHandeler(RenderWindow &window){
  Event event;
  while(window.pollEvent(event)){
    if(optionsText[0].getGlobalBounds().contains(static_cast <Vector2f> (getMousePosition(window)))
    && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
      return 1;
    else if(optionsText[1].getGlobalBounds().contains(static_cast <Vector2f> (getMousePosition(window)))
    && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
      return 2;
    else if(optionsText[2].getGlobalBounds().contains(static_cast <Vector2f> (getMousePosition(window)))
    && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
      return 3;
    else if(optionsText[3].getGlobalBounds().contains(static_cast <Vector2f> (getMousePosition(window)))
    && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
      return 4;
  }
}

int Options::verticalPosition(int height){
  return height/3;
}

int Options::horisontalPosition(int width){
  return width/3;
}

void Options::highlight(RenderWindow &window){
  for(int i = 0; i < 9; i++){
    if(optionsText[i].getGlobalBounds().contains( static_cast <Vector2f> (getMousePosition(window))))
      optionsText[i].setColor(Color::White);
    else optionsText[i].setColor(Color(224, 246, 207));
  }
}

void Options::setFonts(RenderWindow &window, int width, int height){
  getParse();
  for(int i = 0; i < 9; i++){
    optionsText[i].setFont(font);
    optionsText[i].setCharacterSize(20);
    optionsText[i].setString(optionsString[i] + optionsParse[i]);
    optionsText[i].setPosition(horisontalPosition(width), (verticalPosition(height) + i * 30));
    highlight(window);
  }
}

void Options::getParse(){
  optionsParse[0] = to_string(initialisation.getWidth()) + "x" + to_string(initialisation.getHight());
  optionsParse[1] = to_string(initialisation.getVolumeFX());
  optionsParse[2] = to_string(initialisation.getVolumeMusic());
  optionsParse[3] = initialisation.getUpKey();
  optionsParse[4] = initialisation.getDownKey();
  optionsParse[5] = initialisation.getLeftKey();
  optionsParse[6] = initialisation.getRightKey();
  optionsParse[7] = initialisation.getFireKey();
  optionsParse[8] = initialisation.getShieldKey();
}
