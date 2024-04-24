#include "LedBlinker.h"

LedBlinker::LedBlinker(Led &led)
{
  this->led = led;
  lastTimeBlinked = millis();
  blinkDelay = 500;
}

LedBlinker::LedBlinker(Led &led, unsigned long blinkDelay)
{
  this->led = led;
  lastTimeBlinked = millis();
  this->blinkDelay = blinkDelay;
}

void LedBlinker::initLed()
{
  led.init();
}

void LedBlinker::toggleLed()
{
  led.toggle();
}

void LedBlinker::toggleLed(byte val)
{
  led.toggle(val);
}

void LedBlinker::update()
{
  unsigned long timeNow = millis();
  if (timeNow - lastTimeBlinked > blinkDelay) 
  {
    lastTimeBlinked = timeNow;
    toggleLed();
  }
}

void LedBlinker::update(byte val)
{
  unsigned long timeNow = millis();
  if (timeNow - lastTimeBlinked > blinkDelay) 
  {
    lastTimeBlinked = timeNow;
    toggleLed(val);
  }
}