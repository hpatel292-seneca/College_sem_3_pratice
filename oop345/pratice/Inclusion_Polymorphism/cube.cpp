#include"cube.h"

// Polymorphic Objects - Cloning
// Cube.cpp

Cube::Cube(double l) : len(l) {}

Shape* Cube::clone() const
{
    return new Cube(*this);
}

double Cube::volume() const
{
    return len * len * len;
}