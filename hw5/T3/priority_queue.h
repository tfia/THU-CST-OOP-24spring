#pragma once
#include "abstract_compare.h"
#include <algorithm>
#include <vector>

template<class T> class PriorityQueue {
    AbstractCompare<T> * cmp;
    std::vector<T> v;
public:
    PriorityQueue(AbstractCompare<T> *_cmp) : cmp(_cmp) {}
    ~PriorityQueue() {delete cmp;}
    bool empty() {return v.empty();}
    int size() {return v.size();}
    void push(T element)
    {
        v.push_back(element);
        std::sort(v.begin(), v.end(), [this](T a, T b) {return cmp->compare(a, b);});
    }
    void pop()
    {
        std::sort(v.begin(), v.end(), [this](T a, T b) {return cmp->compare(a, b);});
        v.erase(v.begin());
        std::sort(v.begin(), v.end(), [this](T a, T b) {return cmp->compare(a, b);});
    }
    T top()
    {
        return v[0];
    }
};