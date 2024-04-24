#ifndef CIRCLE_H
#define CIRCLE_H
#include<cmath>
#include "shape.h"

class Circle : public Shape2D
{
private:
    double r;
public:
    Circle(double r) : r(r) {}
    double perimeter() const override {return 2.0 * PI * r;}
    double area() const override {return PI * r * r;}
};

#endif