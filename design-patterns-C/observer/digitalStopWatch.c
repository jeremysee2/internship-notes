#include "digitalStopWatch.h"
#include "systemTime.h"
#include "TimeObserver.h"
#include "stdio.h"

// Instance constructor
DigitalStopWatchPtr createDigitalWatch(void) {
    DigitalStopWatchPtr watch = malloc(sizeof *watch);
    if (NULL != watch) {
        // Successfully created -> attach to the subject
        TimeObserver observer = {0};
        observer.instance = watch;
        observer.notification = changedTime;

        attach(&observer);
    }
    return watch;
}

// Instance destructor
void destroyDigitalWatch (DigitalStopWatchPtr watch) {
    // Detach from the subject
    TimeObserver observer = {0};
    observer.instance = watch;
    observer.notification = changedTime;
    detach(&observer);

    // Release the pointer, free memory
    free(watch);
}

// Concrete operations for instance
static void changedTime(void* instance, const SystemTime* newTime)
{
    DigitalStopWatchPtr digitalWatch = instance;
    assert(NULL != digitalWatch);
    updateDisplay(digitalWatch, newTime);
}