#pragma once

#include <iostream>

class Point {
public:
    int x, y;

    Point(int _x = 0, int _y = 0);
    ~Point();
};

std::istream &operator>>(std::istream &in, Point &p);
std::ostream &operator<<(std::ostream &out, const Point &p);
