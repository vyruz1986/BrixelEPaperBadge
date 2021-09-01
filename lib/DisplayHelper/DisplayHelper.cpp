#include "DisplayHelper.h"

DisplayHelper::DisplayHelper()
    : io(SPI, /*CS=*/EPD_CS, /*DC=*/EPD_DC, /*RST=*/EPD_RSET), display(io, /*RST=*/EPD_RSET, /*BUSY=*/EPD_BUSY)
{
}

void DisplayHelper::setup()
{
    display.init();

    display.setTextColor(GxEPD_BLACK);
    const GFXfont *f = &Open_Sans_Bold_12;
    display.setFont(f);

    display.setRotation(1);
}

void DisplayHelper::showBigLogo()
{
    display.drawBitmap(bmp_brixel_big, 0, 0, 250, 64, GxEPD_WHITE);
    display.update();
}

void DisplayHelper::println(uint x, uint y, char const *text)
{
    display.setCursor(x, y);
    display.println(text);
}

void DisplayHelper::update()
{
    display.update();
}