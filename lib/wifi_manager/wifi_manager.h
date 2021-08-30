#include <Arduino.h>
#include <ESPAsync_WiFiManager.h> //https://github.com/khoih-prog/ESPAsync_WiFiManager

class WifiManager
{
public:
    static void setup();

private:
    AsyncWebServer webServer(80);
    DNSServer dnsServer;
}