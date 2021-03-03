#include <Arduino.h>
#include "Display.h"
#include "Button.h"
#include "Audio.h"
#include "Potentiometer.h"

// Components
Button button(4);
Potentiometer potentiometer(A0);
Audio audio(9);
Display display;

// Text labels
String buttonLabel = "Play Tone:";
String potentiometerLabel = "Frequency:";

// Text positions
int x[4] = {0, 0, 0, 0};
int y[4] = {10, 20, 30, 40};

// Other
float delayTime = 400;
int serial = 9600;

// Initialize the project
void setup() {
  Serial.begin(serial);
}

// Device behavior
void loop() {

  // Read input
  int potentioValue = potentiometer.value();
  bool buttonPressed = button.pressed();

  // Create output message
  String msg[4] = {buttonLabel, button.pressedAsStr(),
    potentiometerLabel, String(potentioValue)};

  // Display output message
  // on OLED display
  display.show(x, y, msg);

  // Adjust audio based on input
  audio.adjustToState(buttonPressed, potentioValue);
  
  // Send output message
  // to serial connection
  for (byte i = 0; i < sizeof(msg); i++)
  {
    Serial.print(msg[i]);
  }

  // Add some delay to avoid
  // running at 'full power'
  delay(delayTime);
}
