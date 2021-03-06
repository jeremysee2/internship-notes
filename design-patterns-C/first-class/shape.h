#ifndef SHAPE_H
#define SHAPE_H

#include <stdint.h>
/*
 * Basic implementation of a class, containing only its attributes within the data structure.
 * For more advanced features such as inheritance and polymorphism, need to initialise pointers within the struct, to reference its own methods.
 */

/* Shape's attributes... */
typedef struct {
    int16_t x; /* x-coordinate of Shape's position */
    int16_t y; /* y-coordinate of Shape's position */
} Shape;

/* Shape's operations... */
void Shape_ctor(Shape * const me, int16_t x0, int16_t y0);
void Shape_moveBy(Shape * const me, int16_t dx, int16_t dy);
uint16_t Shape_distanceFrom(Shape const * const me,
                            Shape const * other);

#endif /* SHAPE_H */
