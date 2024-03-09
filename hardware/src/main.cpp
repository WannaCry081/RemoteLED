#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include "ESPWifi.hpp"
#define LED_PIN 12


const String ssid = "WIFI_SSID_HERE";
const String password = "WIFI_PASSWORD_HERE";
bool status = false;


void getLightStatus();

void setup(){

  Serial.begin(115200);
  ESPWifi wifi(ssid, password);


  Serial.printf("Connecting to %s...", ssid);
  while (!wifi.isConnect()) {
    Serial.print(".");
    delay(1000);

    if (!wifi.isSuccess()) {
      Serial.println("\nError connecting to Wifi...");
    }
  }

  if (wifi.isConnect()) {
    Serial.println("");
    wifi.displayStatus();
    pinMode(LED_PIN, OUTPUT);
  }
} 


void loop(){

  if (WiFi.status() == WL_CONNECTED){
    getLightStatus();

    byte power = (status) ? HIGH : LOW;
    digitalWrite(LED_PIN, power);
  }

  delay(500);
}


void getLightStatus() {
  HTTPClient http;

  // Your server endpoint for GET request
  String url = "http://IP_ADDRESS_HERE/api/v1/light/1/";

  // Send GET request
  http.begin(url);
  int httpCode = http.GET();

  if (httpCode > 0) {
    String payload = http.getString();

    // Parse the JSON response
    const size_t capacity = JSON_OBJECT_SIZE(1) + 20; // Adjust the size as needed
    DynamicJsonDocument jsonDocument(capacity);

    deserializeJson(jsonDocument, payload);

    // Extract the "led" value
    status = jsonDocument["led"];

    Serial.println("GET Response: " + payload);
  } else {
    Serial.println("GET request failed");
  }

  http.end();
}
