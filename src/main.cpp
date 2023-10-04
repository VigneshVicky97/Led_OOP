#include "Arduino.h"
#include "Led.h"

#define LED_PIN 2
#define BLINK_DELAY 250

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