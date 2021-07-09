#ifndef NOTIFIER_H
#define NOTIFIER_H

#include "observer.h"

// Interface of subject, as required by observers. Synchronous interface with direct function calls
void attach(const Observer* observer);
void detach(const Observer* observer);

#endif