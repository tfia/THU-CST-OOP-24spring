#include <iostream>
#include <iomanip>

#include "polygon.h"
#include "circle.h"
#include "cone.h"
#include "cylinder.h"

int main()
{
    double n, s, r1;
    std::cin >> n >> s >> r1;

    Shape2D* square = new Polygon(n, s);
    Shape2D* circle = new Circle(r1);

    std::cout << "Polygon Perimeter: " << std::fixed << std::setprecision(4) << square->perimeter() << std::endl;
    std::cout << "Polygon Area: " << std::fixed << std::setprecision(4) << square->area() << std::endl;

    std::cout << "Circle Perimeter: " << std::fixed << std::setprecision(4) << circle->perimeter() << std::endl;
    std::cout << "Circle Area: " << std::fixed << std::setprecision(4) << circle->area() << std::endl;

    double r2, h;
    std::cin >> r2 >> h;

    Shape3D* cone = new Cone(r2, h);
    Shape3D* cylinder = new Cylinder(r2, h);

    std::cout << "Cone Surface Area: " << std::fixed << std::setprecision(4) << cone->area() << std::endl;
    std::cout << "Cone Volume: " << std::fixed << std::setprecision(4) << cone->volume() << std::endl;

    std::cout << "Cylinder Surface Area: " << std::fixed << std::setprecision(4) << cylinder->area() << std::endl;
    std::cout << "Cylinder Volume: " << std::fixed << std::setprecision(4) << cylinder->volume() << std::endl;

    return 0;
}
