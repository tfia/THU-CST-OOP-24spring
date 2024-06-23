#pragma once
#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    a = abs(a), b = abs(b);
    return b ? gcd(b, a % b) : a;
}


class Fraction
{
public:
    ll x, y;
    Fraction(int a) : x(a), y(1) {}
    Fraction(ll x, ll y) : x(x), y(y) {}
    Fraction operator+(const Fraction & a)
    {
        ll ty = y * a.y;
        ll tx = x * a.y + a.x * y;
        if(tx == 0) return Fraction(0);
        ll g = gcd(abs(tx), abs(ty));
        tx /= g; ty /= g;
        return Fraction(tx, ty);
    }
    Fraction operator-(const Fraction & a)
    {
        ll ty = y * a.y;
        ll tx = x * a.y - a.x * y;
        if(tx == 0) return Fraction(0);
        ll g = gcd(abs(tx), abs(ty));
        tx /= g; ty /= g;
        return Fraction(tx, ty);
    }
    Fraction operator*(const Fraction & a)
    {
        ll tx = x * a.x, ty = y * a.y;
        if(tx == 0) return Fraction(0);
        ll g = gcd(abs(tx), abs(ty));
        tx /= g; ty /= g;
        return Fraction(tx, ty);
    }
    Fraction operator/(const Fraction & a)
    {
        ll tx = x * a.y, ty = y * a.x;
        if(tx == 0) return Fraction(0);
        ll g = gcd(abs(tx), abs(ty));
        tx /= g; ty /= g;
        return Fraction(tx, ty);
    }
    friend ostream & operator<<(ostream & os, const Fraction & a);
};

ostream & operator<<(ostream & os, const Fraction & a)
{
    if(a.x == 0)
    {
        os << 0;
        return os;
    }
    if(abs(a.x) % abs(a.y) == 0)
    {
        cout << a.x / a.y;
        return os;
    }
    ll g = gcd(abs(a.x), abs(a.y));
    if((a.x < 0 && a.y > 0) || (a.x > 0 && a.y < 0)) os << "-";
    os << abs(a.x) / g << "/" << abs(a.y) / g;
    return os;
}