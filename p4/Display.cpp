/*
  Display.cpp - Library for OLED Display.
  Created by Nicolai B. Andersen, March 3, 2021.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Display.h"
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

//U8G2_SSD1306_128X64_ALT0_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // SSD1306 and SSD1308Z are compatible
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);    //Low spped I2C
 

Display::Display()
{
  u8g2.begin();
}

void Display::beforeShow()
{
  // clear the internal memory
  u8g2.clearBuffer();                   
  // choose a suitable font
  u8g2.setFont(u8g2_font_ncenB08_tr); 
}

void Display::afterShow()
{
  // transfer internal memory to the display
  u8g2.sendBuffer(); 
}

void Display::addMessage(int x, int y, String msg)
{
  // write something to the internal memory
  u8g2.setCursor(x, y);
  u8g2.print(msg);
}

void Display::show(int x[], int y[], String msg[])
{
  beforeShow();
  
  for (int i = 0; i < sizeof(msg); i++)
  {
    addMessage(x[i], y[i], msg[i]);
  }
  
  afterShow();
}
