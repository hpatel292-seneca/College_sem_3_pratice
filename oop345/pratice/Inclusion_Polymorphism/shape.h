#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

class shape{
    public:
    virtual double volume() const = 0;
    // this clone function is used to get the dynamatic type of the polymerphic object
    virtual shape* clone() const = 0;
};

#endif