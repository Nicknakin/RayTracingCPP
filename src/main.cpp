#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <thread>
#include <vector>

#include "Vector.h"
#include "color.h"
#include "sphere.h"

Sphere sphere{};
Vector camera{-2.f, 0.f, 0.f};
Vector dir{1.f, 0.f, 0.f};

int main(int argc, char** argv) {

    png::image< png::rgba_pixel > image(128, 128);
    for (png::uint_32 y = 0; y < image.get_height(); ++y)
    {
        for (png::uint_32 x = 0; x < image.get_width(); ++x)
        {
            Color calcColor;
            
            auto relX = ((float)x/image.get_width())*2-1;
            auto relY = ((float)y/image.get_height())*2-1;
            
            dir = Vector{relX, relY, 0};
            
            calcColor = (sphere.intersects(camera, dir))? sphere.surfaceColor: Color{0,0,0,255};

            image[y][x] = toPixel(calcColor);
        }
    }
    image.write("rgb.png");
    return 0;
}
