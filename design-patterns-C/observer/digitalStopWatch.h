#ifndef DIGITALSTOPWATCH_H
#define DIGITALSTOPWATCH_H

typedef struct DigitalStopWatch* DigitalStopWatchPtr;

typedef struct
{
    int x;
    int y;
} Display;


struct DigitalStopWatch
{
    Display watchDisplay;
    // Some other attributes for this object
};

#endif