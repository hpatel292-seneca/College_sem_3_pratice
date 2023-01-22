#ifndef SDDS_CUBE_H
#define SDDS_CUBE_H
#include"shape.h"

class Cube: public shape{
    double len;

    public:
    Cube(double len);
    double volume() const;
    shape* clone() const;
}
#endif