/*
  Display.h - Library for OLED Display.
  Created by Nicolai B. Andersen, March 3, 2021.
  Released into the public domain.
*/
#ifndef Display_h
#define Display_h

#include "Arduino.h"

class Display
{
  public:
    Display();
    void show(int x[], int y[], String msg[]);
  private:
    void addMessage(int x, int y, String msg);
    void beforeShow();
    void afterShow();
};

#endif
