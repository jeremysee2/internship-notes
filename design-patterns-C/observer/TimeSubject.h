#ifndef TIMESUBJECT_H
#define TIMESUBJECT_H

#include "TimeObserver.h"

// Interface of subject, as required by observers. Synchronous interface with direct function calls
void attach(const TimeObserver* observer);
void detach(const TimeObserver* observer);

#endif