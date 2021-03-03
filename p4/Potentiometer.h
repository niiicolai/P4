/*
  Potentiometer.h - Library for Potentiometer.
  Created by Nicolai B. Andersen, March 3, 2021.
  Released into the public domain.
*/
#ifndef Potentiometer_h
#define Potentiometer_h

#include "Arduino.h"

class Potentiometer
{
  public:
    Potentiometer(int pin);
    int value();
  private:
    int _pin;
};

#endif
