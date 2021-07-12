#ifndef OBSERVER_H
#define OBSERVER_H

#include "stdio.h"
// Implementation specific use of queue
#include "freertos/queue.h"

// Interface of the observers
typedef void (*GetQueueHandle) (void* instance);

// Incomplete defition
typedef struct Observer* ObserverPtr;

// Class constructor for Observer
ObserverPtr observer_constructor(void* instance);

// Maintain binding between observer and function pointer. instance, is the original observer object
typedef struct
{
    void* instance;
    GetQueueHandle getQueue;
} Observer;

#endif