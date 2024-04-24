#pragma once

#include <string>

template <typename T>
class Hash
{
private:
    int n;

public:
    Hash(int _n) : n(_n) {}
    int operator()(const T &x);
};

template<>
int Hash<int>::operator()(const int &x)
{
    return x % n;
}

template<>
int Hash<std::string>::operator()(const std::string &x)
{
    int ret = 0;
    for (char c : x)
    {
        ret += static_cast<int>(c);
        ret %= n;
    }
    return ret;
}
