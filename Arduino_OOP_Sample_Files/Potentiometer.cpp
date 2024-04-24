#include "Potentiometer.h"

Potentiometer::Potentiometer(byte pin)
{
  this->pin = pin;
}

byte Potentiometer::readState() 
{
  read = analogRead(pin);
  return map(read, 0, 1024, 0, 255);
}