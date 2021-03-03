/*
  Potentiometer.cpp - Library for Potentiometer.
  Created by Nicolai B. Andersen, March 3, 2021.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Potentiometer.h"

Potentiometer::Potentiometer(int pin)
{
  _pin = pin;
}

int Potentiometer::value()
{
  return analogRead(_pin);
}
