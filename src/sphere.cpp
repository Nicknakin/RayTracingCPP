#include "Vector.h"
#include "color.h"
#include "object.h"
#include "sphere.h"

#include <cmath>

Sphere::Sphere(): Object{Vector{0.f,0.f,0.f}, Color{255,255,255,255}, 0.f, 0.f, 0.f}, rad{1.f}, radsq{rad*rad} {}
Sphere::Sphere(Vector pos, Color col, float rad, float transparent, float reflect, float diffuse): Object{pos, col, transparent, reflect, diffuse}, rad{rad}, radsq{rad*rad} {
}

std::array<float, 2> Sphere::distance(Vector rayOrigin, Vector rayDir){
    const auto a = rayDir*rayDir;
    const auto b = -2*(rayDir*(rayOrigin-pos));
    const auto c = (rayOrigin-pos).magSq() - radsq;
    const auto rootpart = sqrt((-b)-4*a*c);
    return {(float) (a-rootpart)/(2*c), (float) (a+rootpart)/(2*c)};
}

bool Sphere::intersects(Vector rayOrigin, Vector rayDir){
    auto a = rayDir*rayDir;
    auto b = 2*(rayDir*(rayOrigin-pos));
    auto c = (rayOrigin-pos).magSq() - radsq;
    auto temp = sqrt(b-4*a*c);
    return temp >= 0;
}

