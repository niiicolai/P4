/*
  Button.cpp - Library for Button.
  Created by Nicolai B. Andersen, March 3, 2021.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Button.h"

Button::Button(int pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
}

int Button::value()
{
  return digitalRead(_pin);
}

bool Button::pressed()
{
  return (Button::value() == HIGH);
}

String Button::pressedAsStr()
{
  bool pressed = (Button::value() == HIGH);  
  return (pressed ? "TRUE" : "FALSE");
}
