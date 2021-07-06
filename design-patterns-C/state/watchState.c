#include "watchState.h"

// "Virtual functions" that describe the interface to the object. Concrete states will be described in derived objects
static void defaultStop(watchStatePtr state) {
    // Get here if not implemented in derived state
}

static void defaultStart(watchStatePtr state) {
    // Get here if not implemented in derived state
}

void defaultImplementation(watchStatePtr state) {
    state->start = defaultStart;
    state->stop  = defaultStop;
}