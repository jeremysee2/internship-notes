#include "observer.h"

// Class constructor for Observer
ObserverPtr observer_constructor(void* instance)
{
    ObserverPtr observer = malloc(sizeof observer);
    if (NULL != observer) {
        // Successfully created -> initialise queue
        Observer observer = {0};
        observer.instance = observer;
        observer.getQueue = getQueueFunction;

        attach(&observer);
    }
    return observer;
}

// function pointer: function to format messaging formats, sent between tasks (Adapter)
// send operation: function pointer to send data between tasks (Adapter)
// 

void getQueueFunction(ObserverPtr observer, void* data) {
	
}