#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    double PI = 3.14159;
    virtual double area() const = 0;
    virtual ~Shape() {}
};

class Shape2D : public Shape {
public:
    virtual double perimeter() const = 0;
    virtual ~Shape2D() {}
};

class Shape3D : public Shape {
public:
    virtual double volume() const = 0;
    virtual ~Shape3D() {}
};

#endif
