#pragma once
#include "Fraction.h"

template<typename T>
T calculate(char type, T x, T y, T z)
{
    if(type == 'A') return (x * x) + (y * y) + (z * z);
    else if(type == 'B') return (x * y) + (y / z) - (x * z);
    else if(type == 'C') return (y * T(3) * z) - ((x * z) / (y - T(2))) - ((x * y) / (z + T(1)));
}