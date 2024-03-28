#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>
#include <cmath>

using std::ostream;
using std::sqrt;

class Complex {
    public:
    double Re, Im;

    Complex(double Re, double Im);
    Complex(double d);
    Complex operator~() const;
    Complex operator-() const;
    friend ostream & operator<<(ostream & os, const Complex & c);
    //TODO
};

Complex operator+(Complex c1, Complex c2);
Complex operator-(Complex c1, Complex c2);
Complex operator*(Complex c1, Complex c2);
Complex operator/(Complex c1, Complex c2);
// Complex operator+(double d, Complex c);

double abs(Complex & c);


//为虚数单位i定义字面量
Complex operator""i(unsigned long long Im);

Complex operator""i(long double Im);

#endif