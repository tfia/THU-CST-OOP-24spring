#include "point.h"

Point::Point(int _x, int _y): x(_x), y(_y) {}

Point::~Point() {}

std::istream &operator>>(std::istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Point &p) {
    out << p.x << " " << p.y;
    return out;
}
