#ifndef Color_inc
#define Color_inc

#include<iostream>
#include<png++/png.hpp>

struct color {
    uint8_t r,g,b,a=0xFF;
};
typedef color Color;

std::ostream& operator<<(std::ostream& os, const Color& col);

Color gradient(Color, Color, float);
Color grayscale(Color);

png::rgba_pixel toPixel(Color col);

#endif
