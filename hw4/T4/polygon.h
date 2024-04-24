#ifndef POLYGON_H
#define POLYGON_H
#include<cmath>
#include "shape.h"

class Polygon : public Shape2D
{
private:
    double n, s;
public:
    Polygon(double n, double s) : n(n), s(s) {}
    double perimeter() const override {return n * s;}
    double area() const override
    {
        double x = n * s * s;
        double y = 4.0 * tan(PI/n);
        return x / y;
    }
};

#endif