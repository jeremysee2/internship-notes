#include <time.h>
#include <stdlib.h>

#define	RAND_MAX 255
#define NUM_OBSERVERS 3

// Function prototypes
void observer1(int value);
void observer2(int value);
void observer3(int value);

// Global variables
void (*observerList[NUM_OBSERVERS])(int) = {&observer1, &observer2, &observer3};

void delay(int ms) {
    clock_t expire = clock() + (ms * CLOCKS_PER_SEC / 1000);
    while (expire > clock());
}

void notifier() {
    int data = rand() % RAND_MAX;
    delay(100);
    for (int i = 0; i < NUM_OBSERVERS; i++) {
        (*observerList[i])(data);
    }
}

void observer1(int value) {
    delay(100);
    printf("Observer 1: %d\n", value);
}

void observer2(int value) {
    delay(100);
    printf("Observer 2: %d\n", value);
}

void observer3(int value) {
    delay(100);
    printf("Observer 3: %d\n", value);
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