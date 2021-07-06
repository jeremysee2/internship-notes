#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

typedef struct {
    Shape super; // Inherited shape, first part of the struct, for inheritance. This allows upcasting, to use base class operations
    uint16_t width;
    uint16_t height;
} Rectangle;

void Rectangle_ctor(Rectangle * const me, int16_t x0, int16_t y0, uint16_t w0, uint16_t h0);
uint32_t Rectangle_area(Rectangle const * const me);

#endif