#include <stdio.h>
#include "shape.h"
#include "rectangle.h"

// Static allocation
Shape s1;
Rectangle r1;

uint32_t area;

int main() {
    Shape s2;                           // Automatic, Stack allocation
    Shape *ps3 = malloc(sizeof(Shape)); // Heap allocation, dynamic memory

    // Initialise objects; constructor
    Shape_ctor(&s1,1,2);
    Shape_ctor(&s2,3,4);
    Shape_ctor(ps3,1,2);
    Rectangle_ctor(&r1,1,2,15,10);

    // Call object operations
    area = Rectangle_area(&r1);

    // Important: Because of how structs arrange their memory, the derived class can use the same operations that the base class has
    Shape_moveBy((Shape *)&r1,1,2);

    free(ps3); // Remember to deallocate unused memory
}