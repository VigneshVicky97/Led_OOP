#include "Arduino.h"

#define LED_PIN 2
#define BLINK_DELAY 250

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_PIN, HIGH);
  Serial.println("ON");
  delay(BLINK_DELAY);
  digitalWrite(LED_PIN, LOW);
  Serial.println("OFF");
  delay(BLINK_DELAY);
}