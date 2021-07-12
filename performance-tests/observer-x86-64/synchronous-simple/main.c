#include <time.h>
#include <stdlib.h>

#define	RAND_MAX 255

void delay(int ms) {
    clock_t expire = clock() + (ms * CLOCKS_PER_SEC / 1000);
    while (expire > clock());
}

void observer(int observerId, int value) {
    delay(100);
    printf("Observer %d: %d\n", observerId, value);
}

void notifier() {
    int data = rand() % RAND_MAX;
    delay(100);
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
    for (;;) {
        loop();
    }
}