#ifndef NOTIFIER_H
#define NOTIFIER_H

#include "observer.h"

// Linked-list containing the objects to be called; and call their functions to notify them directly (synchronous)
typedef struct ListNode
{
    Observer item;
    struct ListNode* next;
} ListNode;

static struct ListNode observers;

// Interface of subject, as required by observers. Synchronous interface with direct function calls
void attach(const Observer* observer);
void detach(const Observer* observer);

#endif