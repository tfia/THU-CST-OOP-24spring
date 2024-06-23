#pragma once
#include <queue>
#include <vector>
#include <deque>
#include <map>
#include <set>

template <typename Key>
class PopStrategy
{
public:
    virtual void visit(Key key) = 0;
    virtual Key pop() = 0;
    virtual void erase(Key key) = 0;
    virtual void clear() = 0;
    virtual ~PopStrategy() {}
};

template <typename Key>
class FIFOStrategy : public PopStrategy<Key>
{
public:
    int cnt;
    std::map<Key, int> mp;
    FIFOStrategy() : cnt(0) {}
    virtual void visit(Key key) override
    {
        if(mp.find(key) == mp.end()) mp[key] = ++cnt;
    }
    virtual void erase(Key key) override
    {
        mp.erase(key);
    }
    virtual Key pop() override
    {
        int mn = 1e9;
        for(auto it : mp) mn = std::min(mn, it.second);
        for(auto it : mp)
        {
            if(it.second == mn)
            {
                auto res = it.first;
                mp.erase(res);
                return res;
            }
        }
        return Key();
    }
    void clear() override
    {
        mp.clear();
        cnt = 0;
    }
    virtual ~FIFOStrategy() {}
};

template <typename Key>
class LRUStrategy : public PopStrategy<Key>
{
public:
    std::map<Key, int> mp;
    int cnt;
    LRUStrategy() : cnt(0) {}
    virtual void visit(Key key) override
    {
        mp[key] = ++cnt;
    }
    virtual void erase(Key key) override
    {
        mp.erase(key);
    }
    virtual Key pop() override
    {
        int mn = 1e9;
        for(auto it : mp) mn = std::min(mn, it.second);
        for(auto it : mp)
        {
            if(it.second == mn)
            {
                auto res = it.first;
                mp.erase(res);
                return res;
            }
        }
        return Key();
    }
    void clear() override
    {
        mp.clear();
        cnt = 0;
    }
    virtual ~LRUStrategy() {}
};