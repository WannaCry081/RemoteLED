#include "ESPWifi.hpp"


ESPWifi::ESPWifi(const String& ssid, const String& password) {
    WiFi.begin(ssid, password);
}