#include"Sphere.h"

// Polymorphic Objects - Cloning
// Cube.cpp

Sphere::Sphere(double l) : len(l) {}

Shape* Sphere::clone() const
{
    return new Sphere(*this);
}

double Sphere::volume() const
{
    return 4.18879 * len * len * len;
}