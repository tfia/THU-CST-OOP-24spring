#pragma once
#include <iostream>
using namespace std;

struct Counter {
public:
    int s, w;
    Counter(int _s = 0, int _w = 0) : s(_s), w(_w) {}
};


template <class T> class MyWeakPtr;
template <class T>
class MySharedPtr {
private:
    T *data;
    Counter *refCount;
    void release()
    {
        // cout << "called" << endl;
        if(--refCount->s == 0)
        {
            if(data != nullptr)
            {
                cout << "data released." << endl;
                delete data;
                data = nullptr;
            }
            if(refCount->w == 0)
            {
                delete refCount;
                refCount = nullptr;
            }
        }
    }
public:
    MySharedPtr()
    {
        data = nullptr;
        refCount = nullptr;
        cout << "my_sptr constructed." << endl;
    }
    MySharedPtr(T *p)
    {
        data = p;
        refCount = new Counter;
        refCount->s++;
        cout << "my_sptr constructed." << endl;
    }
    MySharedPtr(MySharedPtr<T> &&sp)
    {
        cout << "my_sptr constructed." << endl;
        refCount = sp.refCount;
        data = sp.data;
        sp.data = nullptr;
        sp.refCount = nullptr;
    }
    MySharedPtr(const MyWeakPtr<T> &wp)
    {
        cout << "my_sptr constructed." << endl;
        refCount = wp.refCount;
        if(refCount != nullptr) refCount->s++;
        data = wp.data;
    }
    MySharedPtr(const MySharedPtr<T> &sp)
    {
        cout << "my_sptr constructed." << endl;
        refCount = sp.refCount;
        if(refCount != nullptr) refCount->s++;
        data = sp.data;
    }
    ~MySharedPtr()
    {
        cout << "my_sptr destructed." << endl;
        if(refCount != nullptr)
        {
            release();
        }
    }
    MySharedPtr<T>& operator= (MySharedPtr<T> &&sp)
    {
        cout << "my_sptr updated." << endl;
        if(refCount != nullptr)
        {
            release();
        }
        refCount = sp.refCount;
        data = sp.data;
        sp.refCount = nullptr;
        sp.data = nullptr;
        return *this;
    }
    MySharedPtr<T>& operator= (const MySharedPtr<T> &sp)
    {
        cout << "my_sptr updated." << endl;
        if(refCount != nullptr)
        {
            release();
        }
        data = sp.data;
        refCount = sp.refCount;
        if(refCount != nullptr) refCount->s++;
        return *this;
    }

    int use_count()
    {
        if(refCount != nullptr) return refCount->s;
        return 0;
    }
    T& operator* () {return *data;}
    T* operator-> () {return data;}

    operator bool() {return data != nullptr;}

    friend class MyWeakPtr<T>;
};



template <class T>
class MyWeakPtr {
private:
    Counter *refCount;
    T *data;
    void release()
    {
        if(--refCount->w == 0 && refCount->s == 0)
        {
            delete refCount;
            refCount = nullptr;
        }
    }
public:
    MyWeakPtr()
    {
        data = nullptr;
        refCount = nullptr;
        cout << "my_wptr constructed." << endl;
    }
    MyWeakPtr(MySharedPtr<T> &sp)
    {
        cout << "my_wptr constructed." << endl;
        refCount = sp.refCount;
        if(refCount != nullptr) refCount->w++;
        data = sp.data;
    }
    MyWeakPtr(const MyWeakPtr &wp)
    {
        cout << "my_wptr constructed." << endl;
        refCount = wp.refCount;
        if(refCount != nullptr) refCount->w++;
        data = wp.data;
    }
    MyWeakPtr(MyWeakPtr &&wp)
    {
        cout << "my_wptr constructed." << endl;
        if(refCount != nullptr)
        {
            release();
        }
        refCount = wp.refCount;
        data = wp.data;
        wp.data = nullptr;
        wp.refCount = nullptr;
    }
    ~MyWeakPtr()
    {
        if(refCount != nullptr) release();
        cout << "my_wptr destructed." << endl;
    }

    MyWeakPtr<T>& operator= (const MyWeakPtr<T> &wp)
    {
        cout << "my_wptr updated." << endl;
        if(data != nullptr)
        {
            if(refCount != nullptr)
            {
                release();
            }
        }
        refCount = wp.refCount;
        if(refCount != nullptr) refCount->w++;
        data = wp.data;
        return *this;
    }

    MyWeakPtr<T>& operator= (const MySharedPtr<T> &sp)
    {
        cout << "my_wptr updated." << endl;
        if(data != nullptr)
        {
            if(refCount != nullptr)
            {
                release();
            }
            
        }
        refCount = sp.refCount;
        if(refCount != nullptr) refCount->w++;
        data = sp.data;
        return *this;
    }

    MyWeakPtr<T>& operator= (MyWeakPtr<T> &&wp)
    {
        cout << "my_wptr updated." << endl;
        if(refCount != nullptr)
        {
            release();
        }
        refCount = wp.refCount;
        data = wp.data;
        wp.refCount = nullptr;
        wp.data = nullptr;
        return *this;
    }

    
    MySharedPtr<T> lock()
    {
        if(refCount != nullptr && refCount->s > 0) return MySharedPtr<T>(*this);
        return MySharedPtr<T>();
    }

    int use_count()
    {
        if(refCount != nullptr) return refCount->s;
        return 0;
    }

    friend class MySharedPtr<T>;
};
