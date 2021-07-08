#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

// Type of handle is system specific, this example uses `int`
typedef int Handle;


// All interaction from Reactor to an event handler goes through function pointers with the following signatures
typedef Handle (*getHandleFunc) (void* instance);
typedef void (*handleEventFunc) (void* instance);

typedef struct
{
	void* instance;
	getHandleFunc getHandle;
	handleEventFunc handleEvent;
} EventHandler;


#endif