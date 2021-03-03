/*
  Audio.cpp - Library for Audio.
  Created by Nicolai B. Andersen, March 3, 2021.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Audio.h"

Audio::Audio(int pin)
{
  _pin = pin;
  _isActive = false;
}

void Audio::activate(int frequency)
{
  tone(_pin, frequency);
}

void Audio::deactivate()
{
  noTone(_pin);
}

void Audio::adjustToState(bool state, int frequency)
{
  if (!_isActive && state) 
  {
    _isActive = true;
    activate(frequency);
  }
  else if (_isActive && !state)
  {
    _isActive = false;
    deactivate();
  }
}
