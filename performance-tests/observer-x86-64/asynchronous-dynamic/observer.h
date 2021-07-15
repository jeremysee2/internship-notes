#ifndef OBSERVER_H
#define OBSERVER_H

#include <stdlib.h>
#include "queue.h"

#define DEFAULT_DATA 0

typedef struct
{
	queue_t queue;
	int observerId;
	void *data;
} Observer_t;

Observer_t *observer_new(void *data, int observerId, int queue_size);
void observer_free(Observer_t *self);

#endif