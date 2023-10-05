#ifndef WIFIAP1_H
#define WIFIAP1_H

#include "Arduino.h"
#include "WiFi.h"

#define CONNECTION_TIMEOUT 10

class WiFiAP1
{
  private:
    const char* ssid;
    const char* password;
    int timeout_counter = 0;
  public:
    WiFiAP1(const char* ssid, const char* password) 
    {
      this->ssid = ssid;
      this->password = password;
    }  

    void init()
    {
      WiFi.mode(WIFI_STA); //Optional
      WiFi.begin(ssid, password);
      Serial.println("\nConnecting");
      // connect();
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

#endif