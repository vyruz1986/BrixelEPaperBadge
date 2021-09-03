#ifndef _display_helper_h
#define _display_helper_h

#include <Arduino.h>
#include "logos/logos.h"
#include <GxEPD2_BW.h>

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
    GxEPD2_BW<GxEPD2_213_B73, 250> display;

    struct ScreenPos
    {
        uint x = 0, y = 0;
    } mainTextPos;

    void showBigLogo();
};

#endif