#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led
{
private:
  byte pin;
  byte state;
  
public:
  Led() {};  // do not use
  Led(byte pin);
  
  void init();
  void init(byte defaultState);
  void on();
  void on(byte val);
  void off();
  bool isPoweredOn();
  void toggle();
  void toggle(byte val);
};


#endif