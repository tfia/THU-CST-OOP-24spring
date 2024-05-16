#pragma once

template<class T> class AbstractCompare {
public:
    virtual bool compare(T a, T b) = 0;
    virtual ~AbstractCompare() {};
};