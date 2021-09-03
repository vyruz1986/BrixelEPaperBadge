#ifndef _display_helper_h
#define _display_helper_h

#include <Arduino.h>
#include "logos/logos.h"
#include <GxEPD.h>
#include <GxGDEH0213B73/GxGDEH0213B73.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

// FreeFonts from Adafruit_GFX
// #include <Fonts/FreeSans9pt7b.h>
#include "fonts/RobotoMonoBold12pt.h"

#define EPD_CS (5)

#define EPD_BUSY (4)
#define EPD_RSET (16)
#define EPD_DC (17)

class DisplayHelper
{
public:
    DisplayHelper();
    void setup();
    void showStartScreen();
    void showMainScreen();
    void println(uint x, uint y, char const *text);
    void updateAll();
    void updateTextArea();
    void clearText();
    void showText(char const *text);
    enum DisplayMode
    {
        Start,
        Main
    } currentMode = Start;

private:
    GxIO_Class io;
    GxEPD_Class display;

    struct ScreenPos
    {
        uint x = 0, y = 0;
    } mainTextPos;

    void showBigLogo();
};

#endif