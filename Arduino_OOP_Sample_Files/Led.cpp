#include "Led.h"

Led::Led(byte pin)
{
  this->pin = pin;
}

void Led::init()
{
  pinMode(pin, OUTPUT);
  state = LOW;
}

void Led::init(byte defaultState)
{
  state = defaultState;
  init();
  if (defaultState) 
  {
    on();
  } else {
    off();
  }
}

void Led::on()
{
  state = HIGH;
  digitalWrite(pin, state);
}

void Led::off()
{
  state = LOW;
  digitalWrite(pin, state);
}

void Led::toggle()
{
  if (isPoweredOn()) {
    off();
  } else {
    on();
  }
}

bool Led::isPoweredOn()
{
  return (state == HIGH);
}