#ifndef OBSERVER_H
#define OBSERVER_H

#include "stdio.h"

// Interface of the observers
typedef void (*ChangeDataNotification) (void* instance, const uint32_t* newData);

// Maintain binding between observer and function pointer. instance, is the original observer object
typedef struct
{
    void* instance;
    ChangeDataNotification notification;
} Observer;

#endif