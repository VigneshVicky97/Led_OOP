#include "Arduino.h"
#include "Led.h"
#include "Button.h"

#include <WiFi.h>

const char* ssid     = "Vicky";
const char* password = "vicky12345";

#define CONNECTION_TIMEOUT 10

#define LED_PIN 2
#define BUTTON_PIN 0
#define BLINK_DELAY 250

Led led(LED_PIN);
Button button(BUTTON_PIN);

class WiFiAP
{
  private:
    const char* ssid;
    const char* password;
    int timeout_counter = 0;
  public:
    WiFiAP(const char* ssid, const char* password) 
    {
      this->ssid = ssid;
      this->password = password;
    }  

    void init()
    {
      WiFi.mode(WIFI_STA); //Optional
      WiFi.begin(ssid, password);
      Serial.println("\nConnecting");
      connect();
    }

    void connect()
    {
      while(WiFi.status() != WL_CONNECTED)
      {
        Serial.print(".");
        delay(200);
        timeout_counter++;
        if(timeout_counter >= CONNECTION_TIMEOUT*5)
        {
          ESP.restart();
        }
      }
      Serial.println("\nConnected to the WiFi network");
      Serial.print("Local ESP32 IP: ");
      Serial.println(WiFi.localIP());
    }
};

WiFiAP wifiAP(ssid, password);

void setup()
{
  Serial.begin(115200);

  led.init(LOW);
  button.init();
  wifiAP.init();
}

void loop()
{
  if(button.isPressed())
  {
    led.on();
    // Serial.println("Pressed");
  }
  else{
    led.off();
  }
}
