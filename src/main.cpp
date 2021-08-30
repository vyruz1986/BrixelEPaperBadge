#include <GxEPD.h>
#include <GxGDEH0213B73/BitmapExamples.h>
#include <logos.h>

//#include <GxGDEW0213I5F/GxGDEW0213I5F.h>  // 2.13" b/w 104x212 flexible
//#include <GxGDE0213B1/GxGDE0213B1.h>      // 2.13" b/w
// #include <GxGDEH0213B72/GxGDEH0213B72.h> // 2.13" b/w new panel
#include <GxGDEH0213B73/GxGDEH0213B73.h> // 2.13" b/w newer panel

// GxEPD_MinimumExample by Jean-Marc Zingg

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

#define EPD_MOSI (23)
#define EPD_MISO (-1)
#define EPD_SCLK (18)
#define EPD_CS (5)

#define EPD_BUSY (4)
#define EPD_RSET (16)
#define EPD_DC (17)

#define SDCARD_CS (13)
#define SDCARD_MOSI (15)
#define SDCARD_MISO (2)
#define SDCARD_SCLK (14)

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

GxIO_Class io(SPI, /*CS=*/EPD_CS, /*DC=*/EPD_DC, /*RST=*/EPD_RSET);
GxEPD_Class display(io, /*RST=*/EPD_RSET, /*BUSY=*/EPD_BUSY);

void setup()
{
  display.init();
  // display.eraseDisplay();
  // comment out next line to have no or minimal Adafruit_GFX code
  // display.drawPaged(drawHelloWorld); // version for AVR using paged drawing, works also on other processors

  display.setTextColor(GxEPD_BLACK);
  const GFXfont *f = &FreeMonoBold9pt7b;
  display.setFont(f);

  display.setRotation(1);
  display.drawBitmap(bmp_brixel_big, 0, 0, 250, 64, GxEPD_WHITE);
  display.setCursor(0, 80);
  display.println("Initializing...");
  display.update();
  delay(500);
  display.println("Scanning wifi networks...");
  display.update();
}

void loop(){
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