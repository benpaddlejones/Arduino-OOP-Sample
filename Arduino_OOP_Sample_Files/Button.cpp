#include "Button.h"

Button::Button(byte pin)
{
  this->pin = pin;
  this->isPullUp = true;
  this->internalPullUpActivated = true;
  
  lastTimeChanged =millis();
  debounceDelay = 50;
}

Button::Button(byte pin, bool isPullUp, bool internalPullUpActivated)
{
  this->pin = pin;
  this->isPullUp = isPullUp;
  this->internalPullUpActivated = internalPullUpActivated;

  lastTimeChanged = millis();
  debounceDelay = 50;
}

void Button::init()
{
  if (isPullUp && internalPullUpActivated) {
    pinMode(pin, INPUT_PULLUP);
  } else {
    pinMode(pin, INPUT);
  }
  state = digitalRead(pin);
}

void Button::readState() 
{
  unsigned long timeNow = millis();
  if (timeNow - lastTimeChanged > debounceDelay) 
  {
    byte newState = digitalRead(pin);
    if (newState != state) {
      state = newState;
      lastTimeChanged = timeNow;
    }
  }
  state = digitalRead(pin);
}

bool Button::isPressed()
{
  readState();
  if (isPullUp) {
    return (state == HIGH);
  } else {
    return (state == LOW);
  }
}