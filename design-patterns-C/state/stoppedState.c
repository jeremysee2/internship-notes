#include "stoppedState.h"
#include "startedState.h"

static void startWatch(watchStatePtr state) {
    transitionToStarted(state);
}

void transitionToStopped(watchStatePtr state) {
    // Initialise with default implementation to prevent dependency loop in watchState struct
    defaultImplementation(state);
    // Define function for start state
    state->start = startWatch;
}