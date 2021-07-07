#ifndef SYSTEMTIME_H
#define SYSTEMTIME_H

typedef struct SystemTime* SystemTimePtr;

typedef struct SystemTime
{
    int hour;
    int min;
    int sec;
    // Some other attributes for this object
} SystemTime;

SystemTime calculateNewTime();

#endif