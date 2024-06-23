#pragma once
#include <iostream>

using namespace std;

class Animal
{
public:
    virtual void swim() = 0;
    virtual void sing() = 0;
    virtual ~Animal() {}
};