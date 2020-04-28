#ifndef Vector_inc
#define Vector_inc

#include<iostream>

class Vector {
    public:
        Vector();
        Vector(float x, float y, float z);
        Vector(const Vector& v);

        float mag();
        float magSq();
        Vector normalize(); 

        ~Vector();
        
        friend std::ostream& operator<<(std::ostream &os, const Vector &v);
        float operator*(const Vector&);
        Vector operator+(const Vector&);
        Vector operator-(const Vector&);
        Vector& operator+=(const Vector&);
        Vector& operator-=(const Vector&);
        Vector operator%(const Vector&);
        Vector& operator%=(const Vector&);
        Vector operator+(const float&);
        Vector operator-(const float&);
        Vector& operator+=(const float&);
        Vector& operator-=(const float&);
        bool operator<(Vector&);
        bool operator<=(Vector&);
        bool operator>(Vector&);
        bool operator>=(Vector&);
        bool operator==(Vector&);
        
        float x, y, z;
        float magn=-1, magsq=-1;
};

#endif

