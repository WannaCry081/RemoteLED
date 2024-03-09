#include <Arduino.h>
#include "ESPWifi.hpp"
#define LED_PIN 12


const String ssid = "waraykawifi";
const String password = "KaRAOTMO##!";

ESPWifi wifi(ssid, password);

void setup(){

  Serial.begin(115200);

  Serial.printf("Connecting to %s...", ssid);
  while (!wifi.isConnect()) {
    Serial.print(".");
    delay(1000);

    if (!wifi.isSuccess()) {
      Serial.println("\nError connecting to Wifi...");
    }
  }

  if (wifi.isConnect()) {
    wifi.displayStatus();
    pinMode(LED_PIN, OUTPUT);
  }
} 


void loop(){

  if (wifi.isConnect()){
    digitalWrite(LED_PIN, HIGH);
  }
}