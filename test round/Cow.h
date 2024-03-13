#ifndef COW_H
#define COW_H

struct Cow
{
    std::string name;
    int l, u, m;
    Cow(std::string name_, int l_, int u_, int m_) : name(name_), l(l_), u(u_), m(m_) {}
};

#endif