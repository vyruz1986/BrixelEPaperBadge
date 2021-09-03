#include "WifiHelper.h"

WifiHelper::WifiHelper(void (*startApMode)(ESP_WiFiManager *wm), void (*configSaved)())
    : wm(apName)
{
    sprintf(apName, "BrixelBadge%08X", ESP.getEfuseMac());

    // wm.setAPStaticIPConfig(IPAddress(192, 168, 132, 1), IPAddress(192, 168, 132, 1), IPAddress(255, 255, 255, 0));
    wm.setAPCallback(startApMode);
    wm.setSaveConfigCallback(configSaved);
}

void WifiHelper::setup()
{
    wm.autoConnect(apName);
    // wm.resetSettings();
    ESP_LOGI(__FILE__, "Starting config AP with name %s", apName);
    // wm.autoConnect(apName);
    ESP_LOGI(__FILE__, "Connected to ap, IP: %s", WiFi.localIP().toString().c_str());
}

void WifiHelper::loop()
{
}