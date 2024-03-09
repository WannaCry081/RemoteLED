#ifndef ESPWIFI_HPP
#define ESPWIFI_HPP

#include <Arduino.h>


class ESPWifi {
    private:
        short int counter = 0;

    public:
        ESPWifi(const String& ssid, const String& password);
        bool isConnect();
        bool isSuccess();
};

#endif