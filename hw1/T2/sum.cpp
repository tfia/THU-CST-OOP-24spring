#include "functions.h"
#include <iostream>

int sum(int a, int b)
{
#ifdef DEBUG
	std::cout << "running sum(a = " << a << ", b = " << b << ")" << std::endl; 
#endif
	return a + b;
}
