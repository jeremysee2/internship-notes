#include "shape.h" /* Shape class interface */

// Demonstrates ENCAPSULATION with classes
// Taken from https://www.youtube.com/watch?v=dSLodtKuung&list=PLPW8O6W-1chzoLFm2eLy11AoGiYbApjc4&index=1


// Class constructor
void Shape_ctor(Shape * const me, int16_t x0, int16_t y0) {
    me->x = x0;
    me->y = y0;
}

// Class destructor
void Shape_dtor(Shape * me) {
    free(me);
}

// Defining class operations
void Shape_moveBy(Shape * const me, int16_t dx, int16_t dy) {
    me->x += dx;
    me->y += dy;
}

uint16_t Shape_distanceFrom(Shape const * const me,
                            Shape const * other)
{
    int16_t dx = me->x - other->x;
    int16_t dy = me->y - other->y;
    if (dx < 0) {
       dx = -dx;
    }
    if (dy < 0) {
       dy = -dy;
    }
    return dx + dy;
}
