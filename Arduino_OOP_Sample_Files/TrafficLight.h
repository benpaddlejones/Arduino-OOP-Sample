#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <Arduino.h>
#include "Button.h"
#include "Led.h"
#include "LedBlinker.h"
#include "Potentiometer.h"

class TrafficLight
{
private:
  Led redLED;
  Led amberLED;
  LedBlinker amberBlinker;
  Led greenLED;
  Button theButton;
  Potentiometer thePot;

  byte ledBrightness;

  enum trafficLightState {
    STATE_RED,
    STATE_AMBER,
    STATE_GREEN
  };

  int state;

  unsigned long RedStartTime;
  unsigned long AmberStartTime;
  unsigned long GreenStartTime;

  const int RedStateDuration = 2000;
  const int AmberStateDuration = 3000;
  const int GreenStateDuration = 3000;

  void updateLedBrightness();
  
public:
 // TrafficLight() {};  // do not use
  TrafficLight (Led &redLED, Led &amberLED, Led &greenLED, LedBlinker &amberBlinker, Button &theButton, Potentiometer &thePot);
  
  void init();
  
  void RED();
  void AMBER();
  void GREEN();
  void AllOff();

  void update();

  };


#endif