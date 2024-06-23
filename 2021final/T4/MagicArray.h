#pragma once
#include "Instruction.h"
#include <iostream>
#include <vector>

using namespace std;

class plusNumInstruction : public Instruction
{
public:
    int idx;
    double val;
    plusNumInstruction(int idx, double val) : idx(idx), val(val) {}
    virtual void apply(std::vector<int> &vec)
    {
        vec[idx] += val;
    }
    virtual void apply(std::vector<double> &vec)
    {
        vec[idx] += val;
    }
    virtual void output()
    {
        cout << "arr[" << idx << "] += " << val << endl;
    }
};

class copyInstruction : public Instruction
{
public:
    int dst, src;
    copyInstruction(int dst, int src) : dst(dst), src(src) {}
    virtual void apply(std::vector<int> &vec)
    {
        vec[dst] = vec[src];
    }
    virtual void apply(std::vector<double> &vec)
    {
        vec[dst] = vec[src];
    }
    virtual void output()
    {
        cout << "arr[" << dst << "] = arr[" << src << "]" << endl;
    }
};

class plusArrayInstruction : public Instruction
{
public:
    int dst, src;
    plusArrayInstruction(int dst, int src) : dst(dst), src(src) {}
    virtual void apply(std::vector<int> &vec)
    {
        vec[dst] += vec[src];
    }
    virtual void apply(std::vector<double> &vec)
    {
        vec[dst] += vec[src];
    }
    virtual void output()
    {
        cout << "arr[" << dst << "] += arr[" << src << "]" << endl;
    }
};

class coutInstruction : public Instruction
{
public:
    ostream & os;
    int idx;
    coutInstruction(ostream & os, int idx) : os(os), idx(idx) {}
    virtual void apply(std::vector<int> &vec)
    {
        cout << vec[idx];
    }
    virtual void apply(std::vector<double> &vec)
    {
        cout << vec[idx];
    }
    virtual void output()
    {
        cout << "cout << arr[" << idx << "]" << endl;
    }
};

class endlInstruction : public Instruction
{
public:
    virtual void apply(std::vector<int> &vec)
    {
        cout << endl;
    }
    virtual void apply(std::vector<double> &vec)
    {
        cout << endl;
    }
    virtual void output()
    {
        cout << "cout << endl" << endl;
    }
};

class MagicArray;

class endlProxy
{
public:
    MagicArray * p;
    endlProxy(MagicArray * p) : p(p) {}
};

class Proxy
{
public:
    MagicArray * p;
    int idx;
    Proxy(MagicArray * p, int idx) : p(p), idx(idx) {}
    Proxy operator+=(int x);
    Proxy operator+=(double x);
    Proxy operator=(const Proxy & other);
    Proxy operator+=(const Proxy & other);
    friend ostream & operator<<(ostream & os, const Proxy & other);
    friend ostream & operator<<(ostream & os, const endlProxy & other);
};


class MagicArray
{
public:
    vector<Instruction*> v;
    int len;
    MagicArray(int len) : len(len) {}
    Proxy operator[](int i)
    {
        auto p = Proxy(this, i);
        return p;
    }
    void apply(std::vector<int> &vec)
    {
        for(auto & it : v)
        {
            it->apply(vec);
        }
    }
    void apply(std::vector<double> &vec)
    {
        for(auto & it : v)
        {
            it->apply(vec);
        }
    }
    endlProxy endl()
    {
        auto res = endlProxy(this);
        return res;
    }
    std::vector<Instruction*> & getInstructions() {return v;}
};

Proxy Proxy::operator+=(int x)
{
    auto c = new plusNumInstruction(idx, x);
    p->v.push_back(c);
    return *this;
}

Proxy Proxy::operator+=(double x)
{
    auto c = new plusNumInstruction(idx, x);
    p->v.push_back(c);
    return *this;
}

Proxy Proxy::operator=(const Proxy & other)
{
    auto c = new copyInstruction(idx, other.idx);
    p->v.push_back(c);
    return *this;
}

Proxy Proxy::operator+=(const Proxy & other)
{
    auto c = new plusArrayInstruction(idx, other.idx);
    p->v.push_back(c);
    return *this;
}

ostream & operator<<(ostream & os, const Proxy & other)
{
    auto c = new coutInstruction(os, other.idx);
    other.p->v.push_back(c);
    return os;
}

ostream & operator<<(ostream & os, const endlProxy & other)
{
    auto c = new endlInstruction();
    other.p->v.push_back(c);
    return os;
}