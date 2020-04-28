#ifndef Sphere_inc
#define Sphere_inc

#include "Vector.h"
#include "color.h"
#include "object.h"

class Sphere: public Object {
    public:
        Sphere();
        Sphere(Vector pos, Color col, float rad, float transparent, float reflect, float diffuse);

        std::array<float, 2> distance(Vector rayOrigin, Vector rayDir);
        bool intersects(Vector rayOrigin, Vector rayDir);

        float rad, radsq;
};

#endif

