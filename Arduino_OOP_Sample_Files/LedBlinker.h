#ifndef LEDBlinker_H
#define LEDBlinker_H

#include <Arduino.h>
#include "Led.h"

class LedBlinker
{
private:
  Led led;
  unsigned long lastTimeBlinked;
  unsigned long blinkDelay;
  
  void toggleLed();
  void toggleLed(byte val);

public:
  LedBlinker() {} // do not use
  LedBlinker(Led &led);
  LedBlinker(Led &led, unsigned long blinkDelay);
  
  void initLed();

  void update();
  void update(byte val);
};

#endif