#include <stdio.h>
#include "observer.h"
#include "queue.h"

// Constructor for Observer class
Observer_t *observer_new(void *data, int observerId, int queue_size)
{
	Observer_t *self = (Observer_t *) malloc(sizeof(Observer_t));
	self->data = data;
	self->observerId = observerId;
	queue_t observerQueue = {0, 0, queue_size, malloc(sizeof(void*) * queue_size)};
	self->queue = observerQueue;
	return self;
}

// Destructor for observer class
void observer_free(Observer_t *self)
{
	free(self);
}