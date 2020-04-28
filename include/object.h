#ifndef Object_inc
#define Object_inc

#include "Vector.h"

class Object {
    public:
        Object();
        ~Object();
        
        virtual float[2] distance(Vector rayOrigin, Vector rayDir);
        virtual bool intersects(Vector rayOrigin, Vector rayDir);

        const Vector pos;
        const Color surfaceColor;
        const float rad, radsq;
        const float transparent, reflect, diffuse;
};

#endif

