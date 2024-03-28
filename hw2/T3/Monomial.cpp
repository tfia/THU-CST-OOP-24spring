#include "Monomial.h"
#include <cmath>

using namespace std;

Monomial::Monomial()
{
    coe = 0;
    deg = 0;
}

Monomial::Monomial(int _c, int _d) : coe(_c), deg(_d) {}

Monomial Monomial::operator+(const Monomial & x) const
{
    int tc = coe + x.coe, td = deg;
    if(coe == 0) td = x.deg;
    if(tc == 0) td = 0;
    return Monomial(tc, td);
}

Monomial Monomial::operator-(const Monomial & x) const
{
    int tc = coe - x.coe, td = deg;
    if(coe == 0) td = x.deg;
    if(tc == 0) td = 0;
    return Monomial(tc, td);
}

Monomial Monomial::operator*(const Monomial & x) const
{
    int tc = coe * x.coe, td = x.deg + deg;
    if(tc == 0) td = 0;
    return Monomial(tc, td);
}

Monomial Monomial::operator/(const Monomial & x) const
{
    int tc = coe / x.coe, td = deg - x.deg;
    if(tc == 0) td = 0;
    return Monomial(tc, td);
}

int Monomial::get_val(int x)
{
    return coe * pow(x, deg);
}

int Monomial::definite_integral(const int a, const int b)
{
    // Monomial tmp = Monomial(coe / (deg + 1), deg + 1);
    // return tmp.get_val(b) - tmp.get_val(a);
    double x = pow(b, deg + 1), y = pow(a, deg + 1);
    double z = coe / (deg + 1);
    return z * (x - y);
}

Monomial Monomial::derive()
{
    if(deg)
    {
        int td = deg - 1, tc = coe * deg;
        if(tc == 0) td = 0;
        return Monomial(tc, td);
    }
    else return Monomial(0, 0);
}

std::istream & operator>>(std::istream & is, Monomial & x)
{
    string s;
    is >> s;
    int c = 0, d = 0, tmp;
    bool flag = 0;
    for(int i = 0; i <= (int)s.size() - 1; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            c += s[i] - '0';
            c *= 10;
        }
        if(s[i] == '-') flag = 1;
        if(s[i] == 'x')
        {
            c /= 10;
            tmp = i;
            break;
        }
    }
    if(flag) c *= -1;
    flag = 0;
    // cout << "-- " << tmp << endl;
    for(int i = tmp; i <= (int)s.size() - 1; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            d += s[i] - '0';
            d *= 10;
        }
        if(s[i] == '-') flag = 1;
    }
    if(flag) d *= -1;
    d /= 10;
    if(c == 0) d = 0;
    x.coe = c; x.deg = d;
    // cout << "-- " << c << " " << d << endl;
    return is;
}

std::ostream & operator<<(std::ostream & os, Monomial & x)
{
    os << x.coe << "x^" << x.deg << endl;
    return os;
}