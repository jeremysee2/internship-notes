#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void delay(int ms) {
    clock_t expire = clock() + (ms * CLOCKS_PER_SEC / 1000);
    while (expire > clock());
}

void observer(int observerId, int value) {
    printf("Observer %d: %d\n", observerId, value);
}

void notifier() {
    int data = rand() % RAND_MAX;
    // delay(100);
    // Observers hardcoded for now
    observer(0, data);
    observer(1, data);
    observer(2, data);
}

// Initialization, should only be called once.
void setup() {
    srand(time(NULL));
}

void loop() {
    // Emulated notifier, generate a random number and notify observers.
    notifier();
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