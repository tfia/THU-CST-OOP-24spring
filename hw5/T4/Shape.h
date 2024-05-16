#pragma once
#include <string>

template <class RealShape>
class Shape {
protected:
    int a, b;
    static int cnt, alive;
public:
    Shape(int a, int b) : a(a), b(b) {cnt++; alive++;}
    std::string type() {return static_cast<RealShape *>(this)->typeImpl();}
    int area() {return static_cast<RealShape *>(this)->areaImpl();}
    RealShape * print()
    {
        std::string typ = static_cast<RealShape *>(this)->typeImpl();
        int s = static_cast<RealShape *>(this)->areaImpl();
        std::cout << "Area of " << typ << ": " << s << std::endl;
        return static_cast<RealShape *>(this);
    }
    RealShape * zoom(int k)
    {
        a *= k;
        b *= k;
        return static_cast<RealShape *>(this);
    }
    static int getCreate() {return cnt;}
    static int getAlive() {return alive;}
    ~Shape() {alive--;}
};

template <typename RealShape>
int Shape<RealShape>::cnt = 0;
template <typename RealShape>
int Shape<RealShape>::alive = 0;

class Triangle : public Shape<Triangle>
{
public:
    Triangle(int a, int b) : Shape(a, b) {}
    std::string typeImpl() {return "Triangle";}
    int areaImpl() {return (a * b) >> 1;}
    ~Triangle() {}
};

class Rectangle : public Shape<Rectangle>
{
public:
    Rectangle(int a, int b) : Shape(a, b) {}
    std::string typeImpl() {return "Rectangle";}
    int areaImpl() {return a * b;}
    ~Rectangle() {}
};
