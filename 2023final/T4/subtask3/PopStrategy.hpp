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
    virtual void clear() = 0;
};

template <typename Key>
class FIFOStrategy : public PopStrategy<Key>
{
public:
    std::queue<Key> q;
    std::set<Key> st;
    virtual void visit(Key key) override
    {
        if(st.find(key) == st.end())
        {
            st.insert(key);
            q.push(key);
        }
    }
    virtual Key pop() override
    {
        Key t = q.front();
        q.pop();
        st.erase(t);
        return t;
    }
    void clear() override
    {
        while(!q.empty()) q.pop();
        st.clear();
    }
};

template <typename Key>
class LRUStrategy : public PopStrategy<Key>
{
public:
    std::deque<Key> dq;
    virtual void visit(Key key) override
    {
        bool flag = false;
        for(auto it = dq.begin(); it != dq.end(); it++)
        {
            if(*it == key)
            {
                auto t = *it;
                dq.erase(it);
                dq.push_back(t);
                flag = true;
                break;
            }
        }
        if(!flag) dq.push_back(key);
    }
    virtual Key pop() override
    {
        Key t = dq.front();
        dq.pop_front();
        return t;
    }
    void clear() override
    {
        dq.clear();
    }
};