#include "observer.h"
#include "queue.h"

// Constructor for Observer class
Observer *observer_new(void (*callback)(void *), void *data, int observerId, int queue_size)
{
	Observer *self = (Observer *) malloc(sizeof(Observer));
	self->callback = callback;
	self->data = data;
	self->observerId = observerId;
	queue_t observerQueue = {0, 0, queue_size, malloc(sizeof(void*) * queue_size)};
	self->queue = observerQueue;
	return self;
}

// Default callback for an observer to receive data.
void default_callback(Observer *self, void *data)
{
	self->data = data;
	printf("Observer data: %d",*(int *) self->data);
}

// Destructor for observer class
void observer_free(Observer *self)
{
	free(self);
}