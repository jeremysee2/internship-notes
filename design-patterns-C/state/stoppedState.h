#ifndef STOPPEDSTATE_H
#define STOPPEDSTATE_H

#include "watchState.h"

// Entry function to set the pointers in watchState struct, to point to functions specifying the behaviour of the particular state
void transitionToStopped(watchStatePtr state);

#endif