#ifndef OBSERVER_H
#define OBSERVER_H

#include <stdlib.h>

#define DEFAULT_DATA 0

typedef struct
{
	int data;
	int observerID;
} Observer;

Observer *observer_new(int data, int observerID);
void observer_free(Observer *self);
void observer_notify(Observer *self, int data);

#endif