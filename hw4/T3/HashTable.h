#pragma once

#include <string>

#include "Hash.h"

template <typename T1, typename T2>
class HashTable
{
private:
    T2 * mp[5005];
    Hash<T1> * h;
public:
    HashTable(int MOD)
    {
        h = new Hash<T1>(MOD);
    }
    void addItem(const T1 &key, const T2 &value)
    {
        // int k = h->operator()(key);
        int k = (*h)(key);
        mp[k] = new T2(value);
    }
    void removeItem(const T1 &key)
    {
        int k = h->operator()(key);
        mp[k] = nullptr;
    }
    T2 *findByKey(const T1 &key)
    {
        int k = h->operator()(key);
        return mp[k];
    }
};
