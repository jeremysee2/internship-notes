#ifndef DIGITALSTOPWATCH_H
#define DIGITALSTOPWATCH_H

typedef enum {
    stopped,
    started
} State;

typedef struct DigitalStopWatch* DigitalStopWatchPtr;

struct DigitalStopWatch
{
    struct watchState state;
    // Some other attributes for this object
};

#endif