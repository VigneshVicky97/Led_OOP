#include "Arduino.h"

#define LED_PIN 2
#define BLINK_DELAY 250

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

    void on()
    {
      digitalWrite(pin, HIGH);
    }

    void off()
    {
      digitalWrite(pin, LOW);
    }
};

Led led(LED_PIN);

void setup()
{
  led.init();
}

void loop()
{
  led.on();
  delay(BLINK_DELAY);
  led.off();
  delay(BLINK_DELAY);
}