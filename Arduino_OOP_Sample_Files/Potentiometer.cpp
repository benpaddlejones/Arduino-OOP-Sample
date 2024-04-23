#include "Potentiometer.h"

Potentiometer::Potentiometer(byte pin)
{
  this->pin = pin;
}

void Potentiometer::init()
{
  read = analogRead(pin);
}

byte Potentiometer::readState() 
{
  read = analogRead(pin);
  return read;
}