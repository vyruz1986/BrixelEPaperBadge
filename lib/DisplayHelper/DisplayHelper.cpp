#include "DisplayHelper.h"

DisplayHelper::DisplayHelper()
    : io(SPI, /*CS=*/EPD_CS, /*DC=*/EPD_DC, /*RST=*/EPD_RSET), display(io, /*RST=*/EPD_RSET, /*BUSY=*/EPD_BUSY)
{
    currentMode = Start;
}

void DisplayHelper::setup()
{
    display.init();

    display.setTextColor(GxEPD_BLACK);
    const GFXfont *f = &Roboto_Mono_Bold_12;
    display.setFont(f);

    display.setRotation(1);
}

void DisplayHelper::showStartScreen()
{
    this->showBigLogo();
    this->currentMode = Start;
    mainTextPos.y = 80;
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

void DisplayHelper::showText(char const *text)
{
    ESP_LOGI(__FILE__, "startpos: x%i y%i", mainTextPos.x, mainTextPos.y);
    display.setCursor(mainTextPos.x, mainTextPos.y);
    display.println(text);
}

void DisplayHelper::updateAll()
{
    display.update();
}

void DisplayHelper::updateTextArea()
{
    ESP_LOGI(__FILE__, "Updating text area: x %i to %i, y %i to %i", mainTextPos.x, GxEPD_HEIGHT, mainTextPos.y, GxEPD_WIDTH);
    display.updateWindow(mainTextPos.x, mainTextPos.y, GxEPD_HEIGHT, 42);
}