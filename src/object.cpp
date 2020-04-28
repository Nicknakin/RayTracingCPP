#include "object.h"

Object::Object(): Object{Vector{0.f,0.f,0.f}, Color{255,255,255,255}, 0.f, 0.f, 0.f} {}

Object::Object(Vector pos, Color col, float transparent, float reflect, float diffuse): pos{pos}, surfaceColor{col}, transparent{transparent}, reflect{reflect}, diffuse{diffuse} {}

