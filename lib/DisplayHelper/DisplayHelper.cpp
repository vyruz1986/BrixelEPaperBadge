#include "DisplayHelper.h"

DisplayHelper::DisplayHelper()
    : display(GxEPD2_213_B73(/*CS=*/EPD_CS, /*DC=*/EPD_DC, /*RST=*/EPD_RSET, /*BUSY=*/EPD_BUSY))
{
    currentMode = Start;
}

void DisplayHelper::setup()
{
    display.init();

    display.setTextColor(GxEPD_BLACK);
    display.setFont(&Roboto_Mono_Bold_12);

    display.setRotation(1);
}

void DisplayHelper::showStartScreen()
{
    this->showBigLogo();
    this->currentMode = Start;
    mainTextPos.y = 80;
    display.setPartialWindow(0, 80, 240, 40);
}

void DisplayHelper::showBigLogo()
{
    display.setFullWindow();
    display.firstPage();
    display.fillScreen(GxEPD_WHITE);
    display.drawInvertedBitmap(0, 10, bmp_brixel_big, 250, 64, GxEPD_BLACK);
    display.nextPage();
}

void DisplayHelper::showText(char const *text)
{
    ESP_LOGI(__FILE__, "startpos: x%i y%i", mainTextPos.x, mainTextPos.y);

    display.firstPage();
    do
    {
        display.fillScreen(GxEPD_WHITE);
        display.setCursor(mainTextPos.x, mainTextPos.y);
        display.println(text);
        ESP_LOGI(__FILE__, "Setting page?");
    } while (display.nextPage());

    // display.displayWindow(0, 80, 240, 40);
}

void DisplayHelper::updateAll()
{
    display.firstPage();
}
