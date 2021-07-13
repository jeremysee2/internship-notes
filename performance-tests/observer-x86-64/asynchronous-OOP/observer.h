#ifndef OBSERVER_H
#define OBSERVER_H

#include <stdlib.h>
#include "queue.h"

#define DEFAULT_DATA 0

typedef struct
{
	void (*callback)(void *);
	queue_t queue;
	int observerId;
	void *data;
} Observer;

Observer *observer_new(void (*callback)(void *), void *data, int observerId, int queue_size);
void observer_free(Observer *self);
void default_callback(Observer *self, void *data);

#endif