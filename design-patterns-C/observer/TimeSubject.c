#include "TimeSubject.h"
#include "systemTime.h"
#include "stdio.h"

// Linked-list containing the objects to be called; and call their functions to notify them directly (synchronous)
struct ListNode
{
    TimeObserver item;
    struct ListNode* next;
};

// Notification flag
static int isNotifying = 0;

static struct ListNode observers;
static SystemTime currentTime;

// Local helper functions for managing the linked-list (implementation omitted)

static void appendToList(const TimeObserver* observer)
{
    // Append a copy of the observer to the linked-list
}

static void removeFromList(const TimeObserver* observer)
{
    // Identify the observer in the linked-list and remove that node
}

// Implementation of the TimeSubject interface
void attach(const TimeObserver* observer)
{
    assert(NULL != observer);
    appendToList(observer);
    // To constrain, that this does not occur during a Notification
    assert(0 == isNotifying);
}

void detach(const TimeObserver* observer)
{
    assert(NULL != observer);
    removeFromList(observer);
    // To constrain, that this does not occur during a Notification
    assert(0 == isNotifying);
}

// Implementation of the original responsibility of the TimeSource (code for initialisation, etc omitted)
static void msTick()
{
    struct ListNode* node = observers.next;
    // Invoke a function encapsulating the knowledge about time representation
    currentTime = calculateNewTime();
    isNotifying = 1;
    // Walk through the linked-list and notify every observer that another millisecond passed
    while(NULL != node) {
        // NOTE: if an observer detaches itself during a notification, the list containing the nodes may become corrupted
        TimeObserver* observer = &node->item;
        observer->notification(observer->instance, &currentTime);
        node = node->next;
    }
    isNotifying = 0;
}