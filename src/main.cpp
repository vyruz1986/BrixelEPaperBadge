#include <WifiHelper.h>
#include <DisplayHelper.h>

#define BUTTON_1 (39)
#define BUTTONS \
  {             \
    39          \
  }

#define BUTTON_COUNT (1)

#define LED_PIN (19)
#define LED_ON (LOW)

#define ADC_PIN (35)

#define _HAS_ADC_DETECTED_
#define _HAS_LED_
#define _HAS_SDCARD_

void wifiConfigPortalStartCallback(ESP_WiFiManager *wm);

void wifiApConnectedCallback();

DisplayHelper displayHelper;
WifiHelper wifiHelper(wifiConfigPortalStartCallback, wifiApConnectedCallback);

void setup()
{
  Serial.begin(115200);
  ESP_LOGI(__FILE__, "Starting up...");

  displayHelper.setup();
  displayHelper.showStartScreen();
  wifiHelper.setup();

  ESP_LOGI(__FILE__, "Awaiting configuration on AP %s", wifiHelper.apName);
}

void loop()
{
  wifiHelper.loop();
  //   display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
  //   delay(2000);
  //   display.drawExampleBitmap(BitmapExample2, sizeof(BitmapExample2));
  //   delay(5000);
  // #if !defined(__AVR)
  //   display.drawExampleBitmap(BitmapExample3, sizeof(BitmapExample3));
  //   delay(5000);
  //   display.drawExampleBitmap(logo, sizeof(logo));
  //   delay(5000);
  //   display.drawExampleBitmap(first, sizeof(first));
  //   delay(5000);
  //   display.drawExampleBitmap(second, sizeof(second));
  //   delay(5000);
  //   display.drawExampleBitmap(third, sizeof(third));
  //   delay(5000);
  // #endif
  //   display.fillScreen(GxEPD_WHITE);
  // display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  //   display.update();
  //   delay(5000);
  //   // showBoat();
};

void wifiConfigPortalStartCallback(ESP_WiFiManager *wm)
{
  char msg[100];
  snprintf(msg, sizeof(msg), "No known wifi AP in range, configure badge by connecting to:\n%s", wifiHelper.apName);
  ESP_LOGI(__FILE__, "No known wifi AP in range, configure badge by connecting to: %s", wifiHelper.apName);
  // displayHelper.println(0, 80, msg);
  displayHelper.showText(msg);
  displayHelper.updateTextArea();
}

void wifiApConnectedCallback()
{
  ESP_LOGI(__FILE__, "Connected to wifi!");
}