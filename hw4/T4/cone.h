#ifndef CONE_H
#define CONE_H
#include "shape.h"
#include <cmath>

class Cone : public Shape3D
{
private:
    double r, sh, h;
public:
    Cone(double r, double h) : r(r), h(h) {sh = sqrt(r * r + h * h);}
    double volume() const override {return (1.0 / 3.0) * PI * r * r * h;}
    double area() const override {return PI * r * r + PI * r * sh;}
};

#endif