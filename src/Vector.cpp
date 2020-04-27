#include"Vector.h"

#include<cmath>
#include<iostream>

Vector::Vector(): Vector{0.f,0.f,0.f}{
    
}

Vector::Vector(float x, float y, float z): x{x}, y{y}, z{z} {

}

Vector::Vector(const Vector& v): x{v.x}, y{v.y}, z{v.z} {

}


float Vector::mag(){
    return magn = (magn>=0)? magn: std::sqrt(magSq());
}

float Vector::magSq(){
    return magsq = (magsq>=0)? magsq: x*x+y*y+z*z;
}

Vector Vector::normalize() {
    mag();
    return Vector{x/magn, y/magn, z/magn};
}


Vector::~Vector(){

}


std::ostream& operator<<(std::ostream &os, const Vector &v){
    return os << "{" << v.x << "," << v.y << "," << v.z << "}";
}

float Vector::operator*(Vector& v){
    return x*v.x + y*v.y + z*v.z; 
}

Vector Vector::operator+(Vector& v){
    return Vector{x + v.x, y + v.y, z + v.z};
}

Vector Vector::operator-(Vector& v){
    return Vector{x - v.x, y - v.y, z - v.z};
}

Vector& Vector::operator+=(Vector& v){
    x += v.x;
    y += v.y;
    z += v.z;
    magsq = magn = -1.f;
    return *this;
}

Vector& Vector::operator-=(Vector& v){
    x -= v.x;
    y -= v.y;
    z -= v.z;
    magsq = magn = -1.f;
    return *this;
}

Vector Vector::operator%(Vector& v){
    return Vector{y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x};
}

Vector& Vector::operator%=(Vector& v){
    auto tempx = y*v.z - z*v.y;
    auto tempy = z*v.x - x*v.z;
    auto tempz = x*v.y - y*v.x;
    x = tempx;
    y = tempy;
    z = tempz;
    magsq = magn = -1.f;
    return *this;
}


Vector Vector::operator+(float& f){
    return Vector{x+f, y+f, z+f};
}

Vector Vector::operator-(float& f){
    return Vector{x-f, y-f, z-f};
}

Vector& Vector::operator+=(float& f){
    x+=f;
    y+=f;
    z+=f;
    magn = magsq = -1.f;
    return *this;
}

Vector& Vector::operator-=(float& f){
    x-=f;
    y-=f;
    z-=f;
    magn = magsq = -1.f;
    return *this;
}

bool Vector::operator<(Vector& v){
    return magSq() < v.magSq();
}

bool Vector::operator<=(Vector& v){
    return magSq() <= v.magSq();
}

bool Vector::operator>(Vector& v){
    return magSq() > v.magSq();
}

bool Vector::operator>=(Vector& v){
    return magSq() >= v.magSq();
}

bool Vector::operator==(Vector& v){
    return magSq() == v.magSq();
}

