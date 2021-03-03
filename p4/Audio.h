/*
  Audio.h - Library for Audio.
  Created by Nicolai B. Andersen, March 3, 2021.
  Released into the public domain.
*/
#ifndef Audio_h
#define Audio_h

#include "Arduino.h"

class Audio
{
  public:
    Audio(int pin);
    void adjustToState(bool state, int frequency);
  private:
    void activate(int frequency);
    void deactivate();
    int _pin;
    bool _isActive;
};

#endif
