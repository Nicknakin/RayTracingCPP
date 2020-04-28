#ifndef Object_inc
#define Object_inc

#include "Vector.h"
#include "color.h"

#include <array>

class Object {
    public:
        Object();
        Object(Vector pos, Color col, float transparent, float reflect, float diffuse);

        virtual std::array<float, 2> distance(Vector rayOrigin, Vector rayDir) = 0;
        virtual bool intersects(Vector rayOrigin, Vector rayDir) = 0;

        const Vector pos;
        const Color surfaceColor;
        const float transparent, reflect, diffuse;
};

#endif

