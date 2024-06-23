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
    MyDict* dp;
    MyDict() : hit(0), miss(0), cap(1e9), p(nullptr), dp(nullptr) {}
    MyDict(int capacity, PopStrategy<Key>* popStrategyPtr) : hit(0), miss(0), dp(nullptr)
    {
        cap = capacity;
        p = popStrategyPtr;
    }
    MyDict(int capacity, PopStrategy<Key>* popStrategyPtr, MyDict* nextLevelPtr) : hit(0), miss(0)
    {
        cap = capacity;
        p = popStrategyPtr;
        dp = nextLevelPtr;
    }
    void pop(Key key)
    {
        if(mp.find(key) != mp.end())
        {
            if(p != nullptr) p->erase(key);
            mp.erase(mp.find(key));
        }
        else if(dp != nullptr) dp->pop(key);
    }
    Value & operator[] (Key key)
    {
        if(mp.find(key) != mp.end())
        {
            hit++;
            if(p != nullptr) p->visit(key);
            return mp[key];
        }
        miss++;
        if(dp == nullptr)
        {
            if(p != nullptr) p->visit(key);
            mp[key] = Value();
            if(mp.size() > cap) 
                if(p != nullptr) mp.erase(p->pop());
            // for subtask 3
            return mp[key];
        }
        Value res = (*dp)[key];
        dp->mp.erase(key);
        if(dp->p != nullptr) dp->p->erase(key);
        mp[key] = res;
        if(p != nullptr) p->visit(key);
        if(mp.size() > cap && p != nullptr)
        {
            auto t = p->pop();
            (*dp)[t] = mp[t];
            mp.erase(t);
        }
        return mp[key];
    }
    const HitStatsResult hitStats() const
    {
        if(dp == nullptr) return HitStatsResult(hit, miss);
        return HitStatsResult(hit, miss) + dp->hitStats();
    }
    const int size() const
    {
        if(dp == nullptr) return mp.size();
        return mp.size() + dp->size();
    }
    void clear()
    {
        mp.clear();
        if(p != nullptr) p->clear();
        hit = 0; miss = 0;
        if(dp != nullptr) dp->clear();
    }
};