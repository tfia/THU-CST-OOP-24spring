#pragma once

#include "abstract_compare.h"
#include "point.h"
#include <cmath>

bool operator < (Point a, Point b)
{
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

template <typename T>
class CompareInt1 : public AbstractCompare<T>
{
public:
    virtual bool compare(T a, T b) {return a < b;}
    virtual ~CompareInt1() {}
};

template <typename T>
class CompareInt2 : public AbstractCompare<T>
{
public:
    virtual bool compare(T a, T b)
    {
        int ta = a, tb = b;
        int sum1 = 0, sum2 = 0;
        while(ta) {sum1 += ta % 10; ta /= 10;}
        while(tb) {sum2 += tb % 10; tb /= 10;}
        if(sum1 == sum2) return a < b;
        return sum1 < sum2;
    }
};

template <typename T>
class ComparePoint1 : public AbstractCompare<T>
{
public:
    virtual bool compare(T a, T b) {return a < b;}
    virtual ~ComparePoint1() {}
};

template <typename T>
class ComparePoint2 : public AbstractCompare<T>
{
public:
    virtual bool compare(T a, T b)
    {
        double da = sqrt(double(a.x * a.x) + double(a.y * a.y));
        double db = sqrt(double(b.x * b.x) + double(b.y * b.y));
        if(da == db) return a < b;
        else return da < db;
    }
    virtual ~ComparePoint2() {}
};

AbstractCompare<int>* get_compare_int(int type)
{
    if(type == 1)
    {
        auto * p = new CompareInt1<int>();
        return dynamic_cast<AbstractCompare<int>*>(p);
    }
    if(type == 2)
    {
        auto * p = new CompareInt2<int>();
        return dynamic_cast<AbstractCompare<int>*>(p);
    }
    return nullptr;
}

AbstractCompare<Point>* get_compare_point(int type)
{
    if(type == 3)
    {
        auto * p = new ComparePoint1<Point>();
        return dynamic_cast<AbstractCompare<Point>*>(p);
    }
    if(type == 4)
    {
        auto * p = new ComparePoint2<Point>();
        return dynamic_cast<AbstractCompare<Point>*>(p);
    }
    return nullptr;
}