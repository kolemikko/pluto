#ifndef PLUTO_H
#define PLUTO_H

#include <Watchy.h>
#include "Seven_Segment10pt7b.h"
#include "DSEG7_Classic_Regular_15.h"
#include "DSEG7_Classic_Bold_25.h"

class Pluto : public Watchy
{
    using Watchy::Watchy;

public:
    void drawWatchFace();

private:
    void drawTime();
    void drawDate();
    void drawBattery();
};

#endif