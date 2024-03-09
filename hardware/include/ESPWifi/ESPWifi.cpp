#include "ESPWifi.hpp"


ESPWifi::ESPWifi(const String& ssid, const String& password) {
    WiFi.begin(ssid, password);
}


bool ESPWifi::isConnect() {
    return WiFi.status() == WL_CONNECTED;
}