#include "color.h"

#include<cmath>

std::ostream& operator<<(std::ostream& os, const Color& col){
    return os << std::hex << "#" << col.r << col.g << col.b << col.a;
}

Color gradient(Color c1, Color c2, float perc){
    auto r = (uint8_t) sqrt(c1.r*c1.r*(1-perc) + c2.r*c2.r*(perc));
    auto g = (uint8_t) sqrt(c1.g*c1.g*(1-perc) + c2.g*c2.b*(perc));
    auto b = (uint8_t) sqrt(c1.b*c1.b*(1-perc) + c2.b*c2.b*(perc));
    auto a = (uint8_t) sqrt(c1.a*c1.a*(1-perc) + c2.a*c2.a*(perc));
    return Color{r,g,b,a};
}

Color grayscale(Color c){
    auto gray = (uint8_t) sqrt(c.r*c.r/3 + c.g*c.g/3 + c.b*c.b/3);
    return Color{gray, gray, gray, c.a};
}

png::rgba_pixel toPixel(Color c){
    return png::rgba_pixel{c.r, c.g, c.b, c.a};
}
