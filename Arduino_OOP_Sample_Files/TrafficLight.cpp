
#include "TrafficLight.h"

TrafficLight::TrafficLight (Led &redLED, Led &amberLED, Led &greenLED, LedBlinker &amberBlinker, Button &theButton, Potentiometer &thePot)
{
  this->redLED = redLED;
  this->amberLED = amberLED;
  this->greenLED = greenLED;
  this->amberBlinker = amberBlinker;
  this->theButton = theButton;
  this->thePot = thePot;
}

void TrafficLight::init()
{
  redLED.init();
  amberLED.init();
  greenLED.init();
  //thePot.init();
  delay(100);
  
  state = STATE_RED;
  theButton.init();
}

void TrafficLight::RED()
{
  redLED.on();
  amberLED.off();
  greenLED.off();
}

void TrafficLight::AMBER()
{
  redLED.on();
  amberBlinker.update();
  greenLED.off();
}

void TrafficLight::GREEN()
{
  redLED.off();
  amberLED.off();
  greenLED.on();
}

void TrafficLight::AllOff()
{
  redLED.off();
  amberLED.off();
  greenLED.off();
}


void TrafficLight::update()
{
  unsigned long timeNow = millis();
  switch (state)
  {
  case STATE_RED:
  {
    RED();
    if (theButton.isPressed())
    {
      state = STATE_AMBER;
      AmberStartTime = timeNow;
    }
    break;
  }
  case STATE_AMBER:
  {
    AMBER();
    if (timeNow - AmberStartTime > AmberStateDuration)
    {
      state = STATE_GREEN;
      GreenStartTime = timeNow;
    }
    break;
  }
  case STATE_GREEN:
  {
    
    GREEN();
    if (timeNow - GreenStartTime > GreenStateDuration)
    {
      state = STATE_RED;
      RedStartTime = timeNow;
    }
    break;
  }
  default:
  {
    AllOff();
  }
  } 
}