#include <Arduino.h>
#include <ESPAsync_WiFiManager.h>
#include <WiFi.h>

class WifiManager
{
public:
    static void setup()
    {
        AsyncWebServer webServer(80);
        DNSServer dnsServer;

        char name[21];
        sprintf(name, "BrixelBadge%08X", ESP.getEfuseMac());
        ESPAsync_WiFiManager ESPAsync_wifiManager(&webServer, &dnsServer, name);
        ESPAsync_wifiManager.setAPStaticIPConfig(IPAddress(192, 168, 132, 1), IPAddress(192, 168, 132, 1), IPAddress(255, 255, 255, 0));
        ESPAsync_wifiManager.autoConnect(name);
        ESP_LOGI(__FILE__, "Connected to ap, IP: %s", WiFi.localIP().toString().c_str());
    }
};
