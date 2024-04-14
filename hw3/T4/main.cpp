#include <iostream>
#include <vector>
#include "PyObject.h"
#include "test.h"


int main() {
#ifdef subtask1
    PyObject p;
    p = 4;
    std::cout << (int) p << std::endl;
    p = 'r';
    std::cout << (char) p << std::endl;
    char c = p;
    std::cout << c << std::endl;
    p = 1.4;
    std::cout << (double) p << std::endl;
#endif

#ifdef subtask2
    PyObject p;
    p = 'a';
    std::cout << (char) p << std::endl;
    Test t;
    t.id = 99;
    p = t;
    Test t2 = p;
    std::cout << ((Test) p).id << std::endl;
    std::cout << t2.id << std::endl;
#endif

#ifdef subtask3
    PyObject p;
    Test t;
    t.id = 3;
    p = t;
    std::cout << ((Test) p).id << std::endl;
    t.id = 9;
    std::cout << ((Test) p).id << std::endl;
    t.id = 7;
    std::cout << ((Test) p).id << std::endl;
    char c = 'e';
    p = c;
    std::cout << (char) p << std::endl;
    c = 'f';
    std::cout << (char) p << std::endl;
#endif

#ifdef subtask4
    PyObject p;
    p = std::move(*(new Test));
    ((Test &) p).func(6);
    Test t2 = p;
    ((Test &) p).func(10);
    Test &t3 = p;
    t3.func(109);
    t2.func(101);
    char c = 'o';
    p = c;
    std::cout << Test::getCount() << std::endl;
    std::cout << (char) p << std::endl;
    p = t2;
    PyObject p1;
    PyObject p2;
    PyObject p3;
    p1 = &p;
    ((Test &) p1).func(9);
    ((Test &) p).func(99);
    p2 = p1;
    ((Test &) p2).func(999);
    p3 = p;
    p = 1;
    ((Test &) p3).func(919);
    p3 = 0.2;
    std::cout << Test::getCount() << std::endl;
#endif
    return 0;
}