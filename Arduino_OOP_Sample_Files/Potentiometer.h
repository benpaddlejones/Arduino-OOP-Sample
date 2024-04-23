#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <Arduino.h>

class Potentiometer
{
private:
  byte pin;
  byte read;

public:
  Potentiometer() {};  // do not use
  Potentiometer(byte pin);
  
  void init();

  byte readState();
};


#endif