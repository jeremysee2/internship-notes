#include "digitalStopWatch.h"
#include "watchState.h"
#include "startedState.h"
#include "stoppedState.h"
#include "stdio.h"
#include "stdlib.h"

// Instance constructor
DigitalStopWatchPtr createWatch(void) {
    DigitalStopWatchPtr instance = malloc(sizeof *instance);
    if (NULL != instance) {
        // Set initial state
        transitionToStopped(&instance->state);
        // Initialise other attributes here
    }
    return instance;
}

// Instance destructor
void destroyWatch (DigitalStopWatchPtr instance) {
    free(instance);
}

// Concrete operations for instance
void startWatch(DigitalStopWatchPtr instance) {
    instance->state.start(&instance->state);
}

void stopWatch(DigitalStopWatchPtr instance) {
    instance->state.stop(&instance->state);
}