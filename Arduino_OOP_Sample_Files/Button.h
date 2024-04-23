#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button
{
private:
  byte pin;
  bool state;
  bool isPullUp;
  bool internalPullUpActivated;
  unsigned long lastTimeChanged;
  unsigned long debounceDelay;

  void readState();

public:
  Button() {};  // do not use
  Button(byte pin, bool isPullUp, bool internalPullUpActivated);
  Button(byte pin);
  
  void init();
  bool isPressed();
};


#endif