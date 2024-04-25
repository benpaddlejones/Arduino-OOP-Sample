#include "Button.h"
#include "Led.h"
#include "LedBlinker.h"
#include "Potentiometer.h"
#include "TrafficLight.h"

#define RED_PIN 9
#define AMBER_PIN 10
#define GREEN_PIN 11
#define BUTTON_PIN 7
#define POT_PIN A5

  Led redLED(RED_PIN);
  Led amberLED(AMBER_PIN);
  LedBlinker amberBlinker(amberLED, 100);
  Led greenLED(GREEN_PIN);
  Button theButton(BUTTON_PIN);
  Potentiometer thePot(POT_PIN);

  TrafficLight myTrafficLight (redLED, amberLED, greenLED, amberBlinker, theButton, thePot);

void setup() {
  myTrafficLight.init();
}

void loop() {
  myTrafficLight.update();
}