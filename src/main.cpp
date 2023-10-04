#include "Arduino.h"
#include "Led.h"
#include "Button.h"

#define LED_PIN 2
#define BUTTON_PIN 4
#define BLINK_DELAY 250

Led led(LED_PIN);
Button button(BUTTON_PIN);

void setup()
{
  Serial.begin(115200);
  led.init();
  button.init();
}

void loop()
{
  if(button.isPressed())
  {
    led.on();
    Serial.println("Pressed");
  }
  else{
    led.off();
  }
}