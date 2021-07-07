#include "digitalStopWatch.h"
#include "systemTime.h"

static DigitalStopWatchPtr digitalWatch;
static SystemTime currentTime;

// Setup function
void startTimeSource()
{
    digitalWatch = createWatch();
    // Add code for setting up handlers for interrupts, in order to get notified each millisecond from the OS
}

static void msTick()
{
    // Function encapsulating time representation
    currentTime = calculateNewTime();

    // Inform the watch that another millisecond passed
    notifyChangedTime(digitalWatch, &currentTime);
}