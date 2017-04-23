// Paul Schuster
// Arduino
// 4/22/17
// zButton.cpp - definitions for the zButton class

#include "Arduino.h"
#include "zButton.h"

// constructors
ZButton::ZButton(int pin)
{
  _pin = pin;
  _pressed = false;
  pinMode(_pin, INPUT);
}

void ZButton::poll()
{
  int state;
  state = digitalRead(_pin);

  if (state == LOW) {                     // if the button is pressed
    if (_bPress == false) {               //   if we are not checking the bounce
      _bPress = true;
      _time = millis();
    } else {                            //   else we are checking
      if ((millis() - _time) > BOUNCE_DELAY) {    // if the button has been pressed for
        _pressed = true;                        //   some time
      }
    }
  } else {                              // If the button is not pressed
    _bPress = false;                    //   clear all data
    _pressed = false;
  }
}

bool ZButton::isPressed()
{
  return _pressed;
}
