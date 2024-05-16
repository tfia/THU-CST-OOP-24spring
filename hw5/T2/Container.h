#ifndef CONTAINER_H
#define CONTAINER_H
#include "BasicContainer.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using std::vector;
using std::map;

template<class A>
struct Point {
    Pos pos;
    A value;
    Point (Pos p, A v): pos(p), value(v) {}
    bool operator<(const Point & y) {return pos < y.pos;}
};

template<class A, class C>
class Container : public BasicContainer<A> {
public:
    void insert(const Pos &p, const A &v) {};
    A* find(Pos p) { return NULL; };
};

static bool flag = 0;

template <class A>
class Container<A, vector<A> > : public BasicContainer<A> {
    vector< Point<A> > base;
public:
    void insert(const Pos &p, const A &v) {
        base.push_back(Point<A>(p, v));
    }

    A* find(Pos p) {
        if(!flag)
        {
            sort(base.begin(), base.end());
            flag = 1;
        }
        auto it = lower_bound(base.begin(), base.end(), Point<A>(p, A()));
        if(it != base.end() && it->pos == p) return &(it->value);
        return nullptr;
        // for(auto t = base.begin(); t != base.end(); ++t) {
        //     if(p == t->pos) return &(t->value);
        // }
        // return NULL;
    }
};

template <class A>
class Container<A, map<Pos, A> > : public BasicContainer<A>
{
    map<Pos, A> base;
public:
    void insert(const Pos &p, const A &v)
    {
        base.insert(make_pair(p, v));
    }
    A* find(Pos p)
    {
        if(base.find(p) != base.end()) return &base[p];
        return nullptr;
    }
};

#endif