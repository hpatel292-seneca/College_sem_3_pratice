#ifndef SDDS_CUBE_H
#define SDDS_CUBE_H
#include"shape.h"

class Sphere: public shape{
    double len;

    public:
    Sphere(double len);
    double volume() const;
    shape* clone() const;
}
#endif