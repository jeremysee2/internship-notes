#ifndef REACTOR_H
#define REACTOR_H

#include "EventHandler.h"

// Interface of the Reactor
void Register(EventHandler* handler);
void Unregister(EventHandler* handler);

#endif