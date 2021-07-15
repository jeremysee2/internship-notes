#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "queue.h"
#include "observer.h"
#include "linkedList.h"

#define NUM_OBSERVERS 3
#define QUEUE_SIZE 32

// Global variables
linkedListNode_t observerLinkedList;
linkedListNode_t *pointerToObservers = &observerLinkedList;

void delay(int ms) {
    clock_t expire = clock() + (ms * CLOCKS_PER_SEC / 1000);
    while (expire > clock());
}

void notifier() {
    int data = rand();
    // delay(100);
    // Notify observers in linked list
	linkedListNode_t *head = pointerToObservers;
    linkedListNode_t *current = head;
	while (current != NULL) {
        int res = queue_write(&(current->observer.queue), (void*) data);
        current = current->next;
	}
}

// Initialization, should only be called once.
void setup() {
    srand(time(NULL));
    // Initialise linked list of observers, starting with first observer
    linkedListCreate(&pointerToObservers, QUEUE_SIZE);

    for (int i = 1; i < NUM_OBSERVERS; i++) {
        // Create observer objects using observer_new function
        Observer_t *observer = observer_new(DEFAULT_DATA, i, QUEUE_SIZE);
        // Add observer to the linked list
        linkedListInsert(&pointerToObservers, observer);
    }
}

void loop() {
    // Emulated notifier, generate a random number and notify observers.
    notifier();

    // Emulated observer, for each observer in observerList, read from queue and print.
	linkedListNode_t *current = pointerToObservers;
	while (current != NULL) {
        // Read from queue of each observer
        int data = queue_read(&(current->observer.queue));
        // Print data
        printf("Observer %d: %d\n", current->observer.observerId, data);
        current = current->next;
	}
}

// Superloop architecture, common in embedded systems.
int main() {
    setup();
    // Test total number of cycles used in 1000 runs
    double avgCpuCycles = 0;
    for (int i = 0; i < 10000; i++) {
        clock_t start = clock();
        loop();
        clock_t end   = clock();
        avgCpuCycles += ((double) end - start);
    }
    printf("CPU Cycles for 10000 iterations: %lf\n", avgCpuCycles);
}