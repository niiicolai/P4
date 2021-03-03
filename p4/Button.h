/*
  Button.h - Library for Button.
  Created by Nicolai B. Andersen, March 3, 2021.
  Released into the public domain.
*/
#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button
{
  public:
    Button(int pin);
    int value();
    bool pressed();
    String pressedAsStr();
  private:
    int _pin;
};

#endif
