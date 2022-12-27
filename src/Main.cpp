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
    display.setFont(&DSEG7_Classic_Bold_25);
    display.setCursor(5, 53 + 5);
    // int displayHour;
    // if(HOUR_12_24==12){
    //   displayHour = ((currentTime.Hour+11)%12)+1;
    // } else {
    //   displayHour = currentTime.Hour;
    // }
    // if(displayHour < 10){
    //     display.print("0");
    // }
    if (currentTime.Hour < 10)
    {
        display.print("0");
    }
    // display.print(displayHour);
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
    // display.setFont(&Seven_Segment10pt7b);

    // int16_t  x1, y1;
    // uint16_t w, h;

    // String dayOfWeek = dayStr(currentTime.Wday);
    // display.getTextBounds(dayOfWeek, 5, 85, &x1, &y1, &w, &h);
    // if(currentTime.Wday == 4){
    //     w = w - 5;
    // }
    // display.setCursor(85 - w, 85);
    // display.println(dayOfWeek);

    // String month = monthShortStr(currentTime.Month);
    // display.getTextBounds(month, 60, 110, &x1, &y1, &w, &h);
    // display.setCursor(85 - w, 110);
    // display.println(month);

    display.setFont(&DSEG7_Classic_Bold_25);
    display.setCursor(5, 120);
    if (currentTime.Day < 10)
    {
        display.print("0");
    }
    display.print(currentTime.Day);
    display.print("/");

    // display.setCursor(5, 150);
    // display.println(tmYearToCalendar(currentTime.Year));// offset from 1970, since year is stored in uint8_t
    display.setCursor(5, 150);
    if (currentTime.Month < 10)
    {
        display.print("0");
    }
    display.print(currentTime.Month);
}

void Pluto::drawBattery()
{
    display.setFont(&Seven_Segment10pt7b);
    display.setCursor(35, 190);

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