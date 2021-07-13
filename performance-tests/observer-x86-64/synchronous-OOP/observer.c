#include <stdio.h>
#include "observer.h"

// Constructor for Observer class
Observer *observer_new(int data, int observerID)
{
	Observer *self = (Observer *) malloc(sizeof(Observer));
	self->data = data;
	self->observerID = observerID;
	return self;
}

// Call to observer class, to notify the observer of a change
void observer_notify(Observer *self, int data)
{
	self->data = data;
	printf("Observer %d: %d\n", self->observerID, data);
}

// Destructor for observer class
void observer_free(Observer *self)
{
	free(self);
}