#include "ESPWifi.hpp"


ESPWifi::ESPWifi(const String& ssid, const String& password) {
    WiFi.begin(ssid, password);
}


bool ESPWifi::isConnect() {
    return WiFi.status() == WL_CONNECTED;
}


bool ESPWifi::isSuccess() {
    return counter++ < 20;
}


void ESPWifi::displayStatus(){
    const String SSID = WiFi.SSID();
    
    Serial.println("---------------------");
    switch (WiFi.status()){
        case WL_CONNECTED:
            Serial.printf("ESP32 is Connected to %s.\n", SSID);
            break;

        case WL_CONNECT_FAILED:
            Serial.printf("ESP32 Failed to Connect to %s.\n", SSID);
            break;

        case WL_CONNECTION_LOST:
            Serial.printf("ESP32 Lost Connection to %s.\n", SSID);
            break;

        case WL_DISCONNECTED:
            Serial.printf("ESP32 Disconnected to %s.\n", SSID);
            break;
    }

    Serial.printf("IPV4 of %s: ", SSID);
    Serial.print(WiFi.localIP());
    Serial.printf("\nIPV6 of %s: ", SSID);
    Serial.print(WiFi.localIPv6());
    Serial.println("\n---------------------");
}