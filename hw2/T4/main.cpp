#include "Complex.h"
#include <iostream>

using std::cout, std::endl;
int main() {
    //本文件用于测试Complex类，与评测所用测试点不同

    //basic complex test
    Complex c1(1.5, 2.5);
    Complex c2(2, 4);
    Complex c3 = c1 + c2;
    cout << c3 << endl;
    Complex c4 = c1 - c2;
    cout << c4 << endl;
    Complex c5 = c1 * c2;
    cout << c5 << endl;
    Complex c6 = c1 / c2;
    cout << c6 << endl;
    Complex c7 = ~c1;
    cout << c7 << endl;

    Complex c8(0, 4);
    cout << c8 << endl;

    //complex abs test
    cout << abs(c2) << endl;

    //test cout
    cout << Complex(-2, 0) << endl;
    cout << 5 + 3i << endl;


    //answer
    // 3.50 + 6.50i
    // -0.50 - 1.50i
    // -7.00 + 11.00i
    // 0.65 - 0.05i
    // 1.50 - 2.50i
    // 4.00i
    // 4.47
    // -2.00
    // 5.00 + 3.00i

    return 0;

}