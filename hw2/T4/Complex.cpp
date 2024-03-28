#include "Complex.h"
#include <cmath>
#include <iomanip>

using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;
using std::fabs;

Complex::Complex(double Re, double Im) : Re(Re), Im(Im) {}

Complex::Complex(double d) : Re(d), Im(0) {}

Complex operator+(Complex c1, Complex c2)
{
    return Complex(c1.Re + c2.Re, c1.Im + c2.Im);
}

// Complex operator+(double d, Complex c)
// {
//     return Complex(c.Re + d, c.Im);
// }

Complex operator-(Complex c1, Complex c2)
{
    return Complex(c1.Re - c2.Re, c1.Im - c2.Im);
}

Complex operator*(Complex c1, Complex c2)
{
    return Complex(c1.Re * c2.Re - c1.Im * c2.Im, c1.Re * c2.Im + c1.Im * c2.Re);
}

Complex operator/(Complex c1, Complex c2)
{
    double a = c1.Re, b = c1.Im, c = c2.Re, d = c2.Im;
    double x = (a * c + b * d) / (c * c + d * d);
    double y = (b * c - a * d) / (c * c + d * d);
    return Complex(x, y);
}

Complex Complex::operator~() const
{
    return Complex(Re, -Im);
}

Complex Complex::operator-() const
{
    return Complex(-Re, -Im);
}

ostream & operator<<(ostream & os, const Complex & c)
{
    const double eps = 1e-5;
    bool flag = 0;
    os << setprecision(2) << fixed;
    if(fabs(c.Re) < eps && fabs(c.Im) < eps)
    {
        os << "0.00";
        return os;
    }
    if(fabs(c.Re) >= eps) os << c.Re;
    else flag = 1;
    if(fabs(c.Im) >= eps)
    {
        if(!flag)
        {
            if(c.Im > 0) os << " + " << c.Im << "i";
            else os << " - " << -c.Im << "i";
        }
        else os << c.Im << "i";
        
    }
    //cout << endl;
    return os;
}

double abs(Complex & c)
{
    return sqrt(c.Re * c.Re + c.Im * c.Im);
}

Complex operator""i(unsigned long long Im)
{
    return Complex(0, Im);
}

Complex operator""i(long double Im)
{
    return Complex(0, Im);
}