#ifndef POINT
#define POINT

#include "Line.cpp"
#include <iostream>

template <typename T>
class Point
{
public:
    T x, y;
    Point(T x, T y) : x(x), y(y) {}
    void move(T dx, T dy)
    {
        x += dx;
        y += dy;
    }
    void show()
    {
        std::cout << "(" << x << "," << y << ")" << std::endl;
    }
    bool check(Line<T> const & l)
    {
        if(y == l.k * x + l.b) return true;
        return false;
    }
};
#endif