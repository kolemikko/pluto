#include "Main.h"

#define DARKMODE true

void Pluto::drawWatchFace()
{
    display.fillScreen(DARKMODE ? GxEPD_BLACK : GxEPD_WHITE);
    display.setTextColor(DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
    drawTime();
    drawDate();
    drawBattery();
}

void Pluto::drawTime()
{
    display.setFont(&DSEG7_Classic_Regular_39);
    display.setCursor(30, 70);
    if (currentTime.Hour < 10)
    {
        display.print("0");
    }
    display.print(currentTime.Hour);
    display.print(":");
    if (currentTime.Minute < 10)
    {
        display.print("0");
    }
    display.println(currentTime.Minute);
}

void Pluto::drawDate()
{
    display.setFont(&DSEG7_Classic_Bold_25);
    display.setCursor(45, 130);
    if (currentTime.Day < 10)
    {
        display.print("0");
    }
    display.print(currentTime.Day);
    display.print(" -");

    if (currentTime.Month < 10)
    {
        display.print("0");
    }
    display.println(currentTime.Month);
}

void Pluto::drawBattery()
{
    display.setFont(&Seven_Segment10pt7b);
    display.setCursor(150, 190);

    // int8_t batteryLevel = 0;
    float VBAT = getBatteryVoltage();
    display.print(VBAT);
    display.print("V");
    // if(VBAT > 4.1){
    //     batteryLevel = 3;
    // }
    // else if(VBAT > 3.95 && VBAT <= 4.1){
    //     batteryLevel = 2;
    // }
    // else if(VBAT > 3.80 && VBAT <= 3.95){
    //     batteryLevel = 1;
    // }
    // else if(VBAT <= 3.80){
    //     batteryLevel = 0;
    // }
}