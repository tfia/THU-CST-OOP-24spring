#pragma once
#include <iostream>

struct Point {
private:
    int x, y;
public:
    Point();
    Point(int _x, int _y);
    Point(const Point& other);
    ~Point();
    static void show_status();

    friend std::ostream& operator<<(std::ostream& out, const Point& p){
        out << "(" << p.x << "," << p.y << ")";
        return out;
    }
    friend std::istream& operator>>(std::istream& in, Point& p){
        in >> p.x >> p.y;
        return in;
    }
};
