#ifndef OBSERVER_H
#define OBSERVER_H

#include <stdlib.h>

typedef struct
{
	void (*callback)(Observer *self, void *data);
	void *data;
	void *observerID;
} Observer;

Observer *observer_new(void (*callback)(void *), void *data, void *observerID);
void observer_free(Observer *self);
void default_callback(Observer *self, void *data);

int default_data = 0;

#endif