#ifndef Sphere_inc
#define Sphere_inc

#include "Vector.h"
#include "Object.h"

class Sphere: public Object {
    public:
        Sphere();
        ~Sphere();
        
        float[2] distance(Vector rayOrigin, Vector rayDir);
        bool intersects(Vector rayOrigin, Vector rayDir);

        const Vector pos;
        const Color surfaceColor;
        const float rad, radsq;
        const float transparent, reflect, diffuse;
};

#endif

