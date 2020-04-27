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

int main(int argc, char** argv) {
    Color orange{255, 128, 0, 255};
    Color blue{0, 128, 255, 255};

    png::image< png::rgba_pixel > image(128, 128);
    for (png::uint_32 y = 0; y < image.get_height(); ++y)
    {
        for (png::uint_32 x = 0; x < image.get_width(); ++x)
        {
            image[y][x] = toPixel(gradient(blue, orange, (float) x/image.get_width()));
        }
    }
    image.write("rgb.png");
    return 0;
}
