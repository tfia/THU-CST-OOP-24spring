#pragma once
#include "HitStatsResult.hpp"
#include <map>

template<class Key, class Value>
class MyDict
{
public:
    std::map<Key, Value> mp;
    int hit, miss;
    MyDict() : hit(0), miss(0) {}
    Value & operator[] (Key key)
    {
        if(mp.find(key) != mp.end())
        {
            hit++;
            return mp[key];
        }
        else
        {
            miss++;
            mp[key] = Value();
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
        hit = 0; miss = 0;
    }
};