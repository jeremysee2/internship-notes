#ifndef WATCHSTATE_H
#define WATCHSTATE_H

// Incomplete type, supported in C
typedef struct watchState* watchStatePtr;

// Use typedefs for function pointers, to simplify code
typedef void (*eventStartFunc) (watchStatePtr);
typedef void (*eventStopFunc)  (watchStatePtr);

// To add more events, extend the struct with a declaration of another pointer to a function
// To add more states, it has to implement functions for all events supported in that state (the transition functions)
// Minimal changes to the client code in digitalStopWatch.c
struct watchState {
    eventStartFunc start;
    eventStopFunc  stop;
};

void defaultImplementation(watchStatePtr state);

#endif