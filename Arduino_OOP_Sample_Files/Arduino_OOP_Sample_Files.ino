#include <Wire.h> 
#include "LCD_I2C.h"
#include <Servo.h>

LCD_I2C lcd(0x27, 16, 2);
Servo myservo;

void setup() {
  lcd.begin();
  lcd.backlight(); //open the backlight
  myservo.attach(6);
}

void loop() {
  Serial.println(analogRead(A4));
  lcd.setCursor(0, 0);
  lcd.print("Hello World");
}