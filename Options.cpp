#include "Options.h"

Options::Options(){
  loadFont();
  state = OPTIONS;
}

void Options::setFonts(RenderWindow &window, int width, int height){
  getParse();
  for(int i = 0; i < 9; i++){
    optionsText[i].setFont(font);
    optionsText[i].setCharacterSize(40);
    optionsText[i].setString(optionsString[i] + optionsParse[i]);
    optionsText[i].setPosition(horisontalPosition(width), (verticalPosition(height) + i * 30));
  }
  optionsText[9].setFont(font);
  optionsText[9].setCharacterSize(40);
  optionsText[9].setString(optionsString[9]);
  optionsText[9].setPosition(horisontalPosition(width), (verticalPosition(height) + 9 * 40));

  int counter = 3;
  for(int i = 11; i < 17; i++){
    optionsText[i].setFont(font);
    optionsText[i].setCharacterSize(40);
    optionsText[i].setString(pressKeyPopUp);
    optionsText[i].setPosition(horisontalPosition(width) * 2, (verticalPosition(height) + counter++ * 30));
  }
  highlight(window);
}

int Options::displayMenu(RenderWindow &window, int width, int height){
  while(state != RETURN){
    switch(state){
      case optionState::OPTIONS:{
        displayOptions(window, width, height);
        break;
      }
      case optionState::RESOLUTION:{
        displayResolution(window, width, height);
        break;
      }
      case optionState::AUDIO_FX:{
        displayAudioFX(window, width, height);
        break;
      }
      case optionState::AUDIO_MUSIC:{
        displayAudioMusic(window, width, height);
        break;
      }
      case optionState::KEYBINDS:{
        displayKeyBinds(window);
        break;
      }
      case optionState::RETURN:{
        break;
      }
    }
  }
  state = OPTIONS;
  return 0;
}
void Options::displayResolution(RenderWindow &window, int width, int height){

}

void Options::displayAudioFX(RenderWindow &window, int width, int height){

}

void Options::displayAudioMusic(RenderWindow &window, int width, int height){

}

void Options::displayOptions(RenderWindow &window, int width, int height){
  setFonts(window, width, height);
  window.clear(Color(25, 25, 25));
  for(int i = 0; i < 11; i++){
    window.draw(optionsText[i]);
  }
  window.display();
  EventHandeler(window);
}

void Options::displayKeyBinds(RenderWindow &window){
    window.draw(optionsText[keybindValue]);
    window.display();
    if(getKey(window) != "NONE" ){
      state = OPTIONS;
    }
}

int Options::EventHandeler(RenderWindow &window){
  Event event;
  while(window.pollEvent(event)){
    if(optionsText[1].getGlobalBounds().contains(static_cast <Vector2f> (getMousePosition(window)))
    && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left){
      state = RESOLUTION;
    }
    if(optionsText[2].getGlobalBounds().contains(static_cast <Vector2f> (getMousePosition(window)))
    && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left){
      state = AUDIO_FX;
    }
    if(optionsText[3].getGlobalBounds().contains(static_cast <Vector2f> (getMousePosition(window)))
    && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left){
      state = AUDIO_MUSIC;
    }
    if(optionsText[3].getGlobalBounds().contains(static_cast <Vector2f> (getMousePosition(window)))
    && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left){
      keybindValue = 11;
      state = KEYBINDS;
    }
    if(optionsText[4].getGlobalBounds().contains(static_cast <Vector2f> (getMousePosition(window)))
    && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left){
      keybindValue = 12;
      state = KEYBINDS;
    }
    if(optionsText[5].getGlobalBounds().contains(static_cast <Vector2f> (getMousePosition(window)))
    && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left){
      keybindValue = 13;
      state = KEYBINDS;
    }
    if(optionsText[6].getGlobalBounds().contains(static_cast <Vector2f> (getMousePosition(window)))
    && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left){
      keybindValue = 14;
      state = KEYBINDS;
    }
    if(optionsText[7].getGlobalBounds().contains(static_cast <Vector2f> (getMousePosition(window)))
    && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left){
      keybindValue = 15;
      state = KEYBINDS;
    }
    if(optionsText[8].getGlobalBounds().contains(static_cast <Vector2f> (getMousePosition(window)))
    && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left){
      keybindValue = 16;
      state = KEYBINDS;
    }
    if(optionsText[9].getGlobalBounds().contains(static_cast <Vector2f> (getMousePosition(window)))
    && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left){
      keybindValue = 16;
      state = RETURN;
    }
  }
  return 0;
}

int Options::verticalPosition(int height){
  return (height/10) * 3;
}

int Options::horisontalPosition(int width){
  return (width/10) * 3 ;
}

void Options::highlight(RenderWindow &window){
  for(int i = 0; i < 11; i++){
    if(optionsText[i].getGlobalBounds().contains( static_cast <Vector2f> (getMousePosition(window))))
      optionsText[i].setColor(Color::White);
    else optionsText[i].setColor(Color(224, 246, 207));
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

string Options::getKey(RenderWindow &window){
  Event event;
  while(window.pollEvent(event)){
    if(Keyboard::isKeyPressed(sf::Keyboard::Q)){
      return "Q";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::W)){
      return "W";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::E)){
      return "E";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::R)){
      return "R";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::T)){
      return "T";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::Y)){
      return "Y";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::U)){
      return "U";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::I)){
      return "I";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::O)){
      return "O";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::P)){
      return "P";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::A)){
      return "A";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::S)){
      return "S";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::D)){
      return "D";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::F)){
      return "F";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::G)){
      return "G";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::H)){
      return "H";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::J)){
      return "J";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::K)){
      return "K";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::L)){
      return "L";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::Z)){
      return "Z";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::X)){
      return "X";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::C)){
      return "C";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::V)){
      return "V";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::B)){
      return "B";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::N)){
      return "N";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::M)){
      return "M";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::Up)){
      return "Up";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::Down)){
      return "Down";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::Left)){
      return "Left";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::Right)){
      return "Right";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::Space)){
      return "Space";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::LControl)){
      return "LControl";
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::RControl)){
      return "RControl";
    }
  }
  return "NONE";
}
