void WifiManager::setup()
{
    ESPAsync_WiFiManager ESPAsync_wifiManager(&webServer, &dnsServer, "Async_AutoConnect");
    ESPAsync_wifiManager.setAPStaticIPConfig(IPAddress(192, 168, 132, 1), IPAddress(192, 168, 132, 1), IPAddress(255, 255, 255, 0));
    ESPAsync_wifiManager.autoConnect("BrixelBadge" + (uint32_t)ESP.getEfuseMac());
}