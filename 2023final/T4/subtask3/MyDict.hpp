#pragma once
#include "HitStatsResult.hpp"
#include "PopStrategy.hpp"
#include <map>

template<class Key, class Value>
class MyDict
{
public:
    std::map<Key, Value> mp;
    int hit, miss;
    int cap;
    PopStrategy<Key>* p;
    MyDict() : hit(0), miss(0), cap(64), p(nullptr) {}
    MyDict(int capacity, PopStrategy<Key>* popStrategyPtr) : hit(0), miss(0)
    {
        cap = capacity;
        p = popStrategyPtr;
    }
    Value & operator[] (Key key)
    {
        if(p != nullptr) p->visit(key);
        if(mp.size() > cap && p != nullptr)
        {
            auto t = p->pop();
            mp.erase(t);
        }
        if(mp.find(key) != mp.end())
        {
            hit++;
            return mp[key];
        }
        else
        {
            miss++;
            mp[key] = Value();
            if(mp.size() > cap && p != nullptr)
            {
                auto t = p->pop();
                mp.erase(t);
            }
            return mp[key];
        }
    }
    const HitStatsResult hitStats() const
    {
        return HitStatsResult(hit, miss);
    }
    const int size() const
    {
        return mp.size();
    }
    void clear()
    {
        mp.clear();
        if(p != nullptr) p->clear();
        hit = 0; miss = 0;
    }
};