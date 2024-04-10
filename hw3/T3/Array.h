#include <iostream>
#include "Node.h"

using namespace std;

class Array
{
private:
    Node * ptr;
    int len;
public:
    Array(int len) : len(len) {ptr = new Node[len];}
    Array(Array & a) : len(a.len)
    {
        ptr = new Node[len];
        for(int i = 0; i < len; i++) ptr[i] = a.ptr[i];
    }
    Array(Array && a) : len(a.len)
    {
        ptr = a.ptr;
        a.ptr = nullptr;
        a.len = 0;
    }
    Array & operator=(Array & a)
    {
        len = a.len;
        // ptr = new Node[len];
        for(int i = 0; i < len; i++) ptr[i] = a.ptr[i];
        return *this;
    }
    Array & operator=(Array && a)
    {
        len = a.len;
        ptr = a.ptr;
        a.ptr = nullptr;
        a.len = 0;
        return *this;
    }
    Node & operator[] (int i) {return ptr[i];}
    void readArray(Array & a, int l)
    {
        for(int i = 0; i < l; i++) cin >> a[i];
    }
    void outputArray(Array & a, int l)
    {
        for(int i = 0; i < l; i++) cout << a[i] << " ";
        cout << endl;
    }
    ~Array()
    {
        // cout << "--- " << endl;
        // if(ptr != nullptr) for(int i = 0; i < len; i++) cout << ptr[i] << " ";
        // cout << endl;
        delete [] ptr;
    }
};