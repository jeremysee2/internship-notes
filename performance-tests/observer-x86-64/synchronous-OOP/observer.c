#include "observer.h"

// Constructor for Observer class
Observer *observer_new(void (*callback)(void *), void *data, void *observerID)
{
	Observer *self = (Observer *) malloc(sizeof(Observer));
	self->callback = callback;
	self->data = data;
	self->observerID = observerID;
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