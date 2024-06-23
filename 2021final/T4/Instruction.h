#pragma once
#include <vector>

class Instruction
{
public:
    virtual void apply(std::vector<int> &vec) = 0;
    virtual void apply(std::vector<double> &vec) = 0;
    virtual void output() = 0;
};

