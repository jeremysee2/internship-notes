#include "startedState.h"
#include "stoppedState.h"

static void stopWatch(watchStatePtr state) {
    transitionToStopped(state);
}

void transitionToStarted(watchStatePtr state) {
    // Initialise with default implementation to prevent dependency loop in watchState struct
    defaultImplementation(state);
    // Define function for stop state
    state->stop = stopWatch;
}


// // Alternative: stateless entry function
// // Also, client code (digitalStopWatch.c) needs to define a callback function at state transitions
// watchStatePtr transitionToStarted(void)
// {
//     static struct watchState startedState;
//     static int initialised = 0;
//     if (0 == initialised)
//         {
//         defaultImplementation(&startedState);
//         startedState.stop = stopWatch;
//         initialised = 1
//         }
//     return &startedState;
// }

// // In digitalStopWatch.c client code:
// void changeState(digitalStopWatchPtr instance, watchStatePtr newState)
// {
//     // All state transitions have to go through this function
//     instance->state = newState;
// }

// // In stoppedState.c, also need to reimplement transitionToStarted()
// static void startWatch(DigitalStopWatchPtr context)
// {
//     changeState(context, transitionToStarted());
// }