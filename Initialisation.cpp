#include "Initialisation.h"

  void Initialisation::test(){
    if(!ifstream("data/core/config.xml")){
      loadDefaultConfig();
    }
    else loadConfig();
  }

  void Initialisation::loadConfig(){
    xml_document doc;
    doc.load_file("data/core/config.xml");
    xml_node config = doc.child("config");
    setWidth(stoi(config.child("graphics").attribute("width").value()));
    setHight(stoi(config.child("graphics").attribute("hight").value()));
    setMode(config.child("graphics").attribute("mode").value());
    setVolumeFX(stoi(config.child("audio").attribute("fx").value()));
    setVolumeMusic(stoi(config.child("audio").attribute("music").value()));
    setUpKey(config.child("keyBinds").attribute("up").value());
    setDownKey(config.child("keyBinds").attribute("down").value());
    setLeftKey(config.child("keyBinds").attribute("left").value());
    setRightKey(config.child("keyBinds").attribute("right").value());
    setFireKey(config.child("keyBinds").attribute("fire").value());
    setShieldKey(config.child("keyBinds").attribute("shield").value());
  }

  void Initialisation::loadDefaultConfig(){
    setWidth(800);
    setHight(600);
    setMode("fullscreen");
    setVolumeFX(100);
    setVolumeMusic(100);
    setUpKey("Up");
    setDownKey("Down");
    setLeftKey("Left");
    setRightKey("Right");
    setFireKey("Space");
    setShieldKey("LControl");
  }

  //save current class fields to xml config file
  void Initialisation::saveConfig(){
    xml_document doc;
    doc.load_file("data/core/config.xml");
    xml_node config = doc.child("config");
    //graphics settings
    xml_node graphics = config.child("graphics");
    xml_attribute width = graphics.attribute("width");
    width.set_value(getWidth());
    xml_attribute hight = graphics.attribute("hight");
    hight.set_value(getHight());
    xml_attribute mode = graphics.attribute("mode");
    string str = "dfdfd";
    mode.set_value(getMode().c_str());
    //audio settings
    xml_node audio = config.child("audio");
    xml_attribute fx = graphics.attribute("fx");
    fx.set_value(getVolumeFX());
    xml_attribute music = graphics.attribute("music");
    music.set_value(getVolumeMusic());
    //keyBinds settings
    xml_node keyBinds = config.child("keyBinds");
    xml_attribute up = graphics.attribute("up");
    up.set_value(getUpKey().c_str());
    xml_attribute down = graphics.attribute("down");
    down.set_value(getDownKey().c_str());
    xml_attribute left = graphics.attribute("left");
    left.set_value(getLeftKey().c_str());
    xml_attribute right = graphics.attribute("right");
    right.set_value(getRightKey().c_str());
    xml_attribute fire = graphics.attribute("fire");
    fire.set_value(getFireKey().c_str());
    xml_attribute shield = graphics.attribute("shield");
    shield.set_value(getShieldKey().c_str());
    //save config
    doc.save_file("data/core/config.xml");

/*
      doc.save_file("data/core/config.xml");
*/
  }
  //graphics setters & getters
  int Initialisation::getWidth(){
    return width;
  }

  void Initialisation::setWidth(int newWidth){
    width = newWidth;
  }

  int Initialisation::getHight(){
    return hight;
  }

  void Initialisation::setHight(int newHight){
    hight = newHight;
  }

  string Initialisation::getMode(){
    return mode;
  }

  void Initialisation::setMode(string newMode){
    mode = newMode;
  }
  //audio setters & getters
  int Initialisation::getVolumeFX(){
    return volumeFX;
  }

  void Initialisation::setVolumeFX(int newVolumeFX){
    volumeFX = newVolumeFX;
  }

  int Initialisation::getVolumeMusic(){
    return volumeMusic;
  }

  void Initialisation::setVolumeMusic(int newVolumeMusic){
    volumeMusic = newVolumeMusic;
  }
  //keyBinds setters & getters
  string Initialisation::getUpKey(){
    return upKey;
  }

  void Initialisation::setUpKey(string newUp){
    upKey = newUp;
  }

  string Initialisation::getDownKey(){
    return downKey;
  }

  void Initialisation::setDownKey(string newDown){
    downKey = newDown;
  }

  string Initialisation::getLeftKey(){
    return leftKey;
  }

  void Initialisation::setLeftKey(string newLeft){
    leftKey = newLeft;
  }

  string Initialisation::getRightKey(){
    return rightKey;
  }

  void Initialisation::setRightKey(string newRight){
    rightKey = newRight;
  }

  string Initialisation::getFireKey(){
    return fireKey;
  }

  void Initialisation::setFireKey(string newFire){
    fireKey = newFire;
  }

  string Initialisation::getShieldKey(){
    return shieldKey;
  }

  void Initialisation::setShieldKey(string newShield){
    shieldKey = newShield;
  }
