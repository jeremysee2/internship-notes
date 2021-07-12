#include <time.h>
#include <stdlib.h>
#include "queue.h"

#define	RAND_MAX 255
#define NUM_OBSERVERS 3
#define QUEUE_SIZE 32

// Global variables
queue_t observerList[NUM_OBSERVERS] = {0};

void delay(int ms) {
    clock_t expire = clock() + (ms * CLOCKS_PER_SEC / 1000);
    while (expire > clock());
}

void notifier() {
    int data = rand() % RAND_MAX;
    delay(100);
    // Notify observers
    for (int i = 0; i < NUM_OBSERVERS; i++) {
        // Write to queue of each observer
        int res = queue_write(&(observerList[i]), (void*)(data));
        assert((i == QUEUE_SIZE - 1) ? res == -1: res == 0);
    }
}

// Initialization, should only be called once.
void setup() {
    srand(time(NULL));
    queue_t observerQueue1 = {0, 0, QUEUE_SIZE, malloc(sizeof(void*) * QUEUE_SIZE)};
    queue_t observerQueue2 = {0, 0, QUEUE_SIZE, malloc(sizeof(void*) * QUEUE_SIZE)};
    queue_t observerQueue3 = {0, 0, QUEUE_SIZE, malloc(sizeof(void*) * QUEUE_SIZE)};
    observerList[0] = observerQueue1;
    observerList[1] = observerQueue2;
    observerList[2] = observerQueue3;
}

void loop() {
    // Emulated notifier, generate a random number and notify observers.
    notifier();
    // Emulated observer, read from queue and print the data.
    for (int i = 0; i < NUM_OBSERVERS; i++) {
        int data;
        data = (int) queue_read(&(observerList[i]));
        printf("Observer %d: %d\n", i, data);
    }
}

// Superloop architecture, common in embedded systems.
int main() {
    setup();
    for (;;) {
        loop();
    }
}