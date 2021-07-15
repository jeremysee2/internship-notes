#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "queue.h"
#include "observer.h"

#define NUM_OBSERVERS 3
#define QUEUE_SIZE 32

// Global variables
Observer *observerList[NUM_OBSERVERS] = {0};

void delay(int ms) {
    clock_t expire = clock() + (ms * CLOCKS_PER_SEC / 1000);
    while (expire > clock());
}

void notifier() {
    int data = rand();
    // delay(100);
    // Notify observers
    for (int i = 0; i < NUM_OBSERVERS; i++) {
        // Write to queue of each observer
        int res = queue_write(&(observerList[i]->queue), (void*)(data));
        assert((i == QUEUE_SIZE - 1) ? res == -1: res == 0);
    }
}

// Initialization, should only be called once.
void setup() {
    srand(time(NULL));

    for (int i = 0; i < NUM_OBSERVERS; i++) {
        // Create observer objects using observer_new function
        Observer *observer = observer_new(DEFAULT_DATA, i, QUEUE_SIZE);
        // Add observer to the list
        observerList[i] = observer;
    }
}

void loop() {
    // Emulated notifier, generate a random number and notify observers.
    notifier();

    // Emulated observer, for each observer in observerList, read from queue and print.
    for (int i = 0; i < NUM_OBSERVERS; i++) {
        // Read from queue of each observer
        int data = queue_read(&(observerList[i]->queue));
        // Print data
        printf("Observer %d: %d\n", observerList[i]->observerId, data);
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