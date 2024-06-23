#ifndef LINE
#define LINE

#include <iostream>

template <typename T>
class Line
{
public:
    T k, b;
    Line(T k, T b) : k(k), b(b) {}
    Line(T k) : k(k), b(0) {}
    bool intersect(const Line & other)
    {
        if(k == other.k && b == other.b) return true;
        if(k != other.k) return true;
        return false;
    }
    void show()
    {
        std::cout << k << "," << b << std::endl;
    }
    bool operator<(const Line & other)
    {
        return k < other.k;
    }
};
#endif