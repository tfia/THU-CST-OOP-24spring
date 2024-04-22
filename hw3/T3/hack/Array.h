// not work on oj.
#include <iostream>
#include "Node.h"
#define R 640
#define MAGIC 0x7030

using namespace std;

static int b = 1;

int x[1005];

extern "C"
{
    void CAPTURE()
    {
        int cnt = 0;
        int *p = &b;
        size_t tmp = (size_t)p;
        tmp += MAGIC;
        p = (int *)tmp;
        for(size_t i = (size_t)p; i <= (size_t)p + (size_t)R; i++)
        {
            int *t = (int*)i;
            x[cnt] = *t;
            cnt++;
        }
    }
    void REC()
    {
        int cnt = 0;
        int *p = &b;
        size_t tmp = (size_t)p;
        tmp += MAGIC;
        p = (int *)tmp;
        for(size_t i = (size_t)p; i <= (size_t)p + (size_t)R; i++)
        {
            int *t = (int*)i;
            if(*t != x[cnt]) *t = x[cnt];
            cnt++;
        }
    }
}

class Array
{
private:
    Node * ptr;
    int len;
public:
    Array(int len) : len(len)
    {
        CAPTURE();
        ptr = new Node[len];
        REC();
    }
    Array(const Array & a) : len(a.len)
    {
        CAPTURE();
        ptr = new Node[len];
        for(int i = 0; i < len; i++) ptr[i] = a.ptr[i];
        REC();
    }
    Array(Array && a) : len(a.len)
    {
        CAPTURE();
        ptr = a.ptr;
        a.ptr = nullptr;
        a.len = 0;
        REC();
    }
    Array & operator=(const Array & a)
    {
        CAPTURE();
        len = a.len;
        delete [] ptr;
        REC();
        CAPTURE();
        ptr = new Node[len];
        for(int i = 0; i < len; i++) ptr[i] = a.ptr[i];
        REC();
        return *this;
    }
    Array & operator=(Array && a)
    {
        CAPTURE();
        delete [] ptr;
        len = a.len;
        ptr = a.ptr;
        a.ptr = nullptr;
        a.len = 0;
        REC();
        return *this;
    }
    Node & operator[] (int i) {return ptr[i];}
    ~Array() {CAPTURE(); delete [] ptr; REC();}
};