#ifndef LED_H
#define LED_H

#include "Arduino.h"

class Led
{
  private:
    byte pin;
  public:
    Led() {}  // Default Constructor

    Led(byte pin)
    {
      this->pin = pin;
      init();
    }

    void init()
    {
      pinMode(pin, OUTPUT);
    }

    void init(byte defaultState)
    {
      if(defaultState == HIGH)
      {
        on();
      }
      else
      {
        off();
      }
    }

    void on()
    {
      digitalWrite(pin, HIGH);
    }

    void off()
    {
      digitalWrite(pin, LOW);
    }
};

#endif