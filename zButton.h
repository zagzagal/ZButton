// Paul Schuster
// Arduino
// 4/22/17
// zButton.h - header for an Arduino button class

#ifndef ZBUTTON_H
#define ZBUTTON_H

const int BOUNCE_DELAY = 100;

class ZButton
{
  public:
    //constructor
    ZButton(int pin);
    //void setPin(int pin);
    
    void poll();

    bool isPressed();
  private:
    int _pin;
    unsigned long _time;
    bool _bPress;
    bool _pressed;
};

#endif
    
