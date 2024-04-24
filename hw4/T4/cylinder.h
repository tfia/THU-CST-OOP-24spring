#ifndef CYLINDER_H
#define CYLINDER_H
#include "shape.h"

class Cylinder : public Shape3D
{
private:
    double r, h;
public:
    Cylinder(double r, double h) : r(r), h(h) {}
    double volume() const override {return PI * r * r * h;}
    double area() const override {return 2.0 * PI * r * r + 2.0 * PI * r * h;}
};

#endif