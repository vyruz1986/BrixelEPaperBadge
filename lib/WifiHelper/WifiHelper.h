#ifndef _wifi_helper_h
#define _wifi_helper_h

#include <Arduino.h>
#include <ESP_WiFiManager.h>
#include <WiFi.h>

class WifiHelper
{
public:
    char apName[21];

    WifiHelper(void (*startApMode)(ESP_WiFiManager *wm), void (*configSaved)());
    void setup();
    void loop();

private:
    ESP_WiFiManager wm;
};

#endif