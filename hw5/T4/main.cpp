#include <iostream>
#include "Shape.h"

int main() {
#ifdef SUBTASK1
    Rectangle *A = new Rectangle(3, 4);
    std::cout << A->type() << " " << A->area() << "\n";
#endif

#ifdef SUBTASK2
    Triangle *A = new Triangle(2, 5);
    A->zoom(2)->print();
#endif

#ifdef SUBTASK3
    Triangle *A = new Triangle(2, 5);
    std::cout << Triangle::getCreate() << "\n";
    {
        Triangle *B = new Triangle(1, 10);
        std::cout << Triangle::getAlive() << "\n";
        delete B;
    }
    std::cout << Triangle::getCreate() << "\n";
    std::cout << Triangle::getAlive() << "\n";
#endif

#ifdef SUBTASK4
    Rectangle *A[4];
    A[0] = new Rectangle(2, 5);
    for (int i = 0; i < 3; i++) {
        A[i]->print()->zoom(2)->zoom(3)->print();
        A[i + 1] = A[i];
        std::cout << Rectangle::getCreate() << " " << Rectangle::getAlive() << "\n";
    }
#endif
}