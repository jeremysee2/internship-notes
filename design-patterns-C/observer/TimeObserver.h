#ifndef TIMEOBSERVER_H
#define TIMEOBSERVER_H

typedef struct SystemTime
{
    int hours;
    int mins;
    int days;
} SystemTime;


// Interface of the observers
typedef void (*ChangeTimeNotification) (void* instance, const SystemTime* newTime);

// Maintain binding between observer and function pointer. instance, is the original observer object
typedef struct
{
    void* instance;
    ChangeTimeNotification notification;
} TimeObserver;

#endif