#include <iostream>
#include "test.h"

using namespace std;

class PyObject
{
private:
    char C; 
    int I;
    double D;
    Test * Tp = nullptr;
    bool is_owned = 0;
public:
    PyObject() {}
    PyObject(char C) : C(C) { cout << "PyObject got a value" << endl; }
    PyObject(int I) : I(I) { cout << "PyObject got a value" << endl; }
    PyObject(double D) : D(D) { cout << "PyObject got a value" << endl; }
    PyObject(Test & T)
    {
        cout << "PyObject got a value" << endl;
        cout << "Borrowing" << endl;
        Tp = &T;
    }
    PyObject(Test && T)
    {
        cout << "PyObject got a value" << endl;
        Tp = new Test(move(T));
        cout << "Owning" << endl;
        is_owned = 1;
    }
    PyObject(PyObject & P)
    {
        cout << "PyObject got a value" << endl;
        C = P.C;
        I = P.I;
        D = P.D;
        Tp = P.Tp;
        if(P.is_owned) P.Tp = nullptr;
    }
    PyObject(PyObject * P)
    {
        cout << "PyObject got a value" << endl;
        C = P->C;
        I = P->I;
        D = P->D;
        Tp = P->Tp;
    }
    PyObject & operator=(char C)
    {
        cout << "PyObject got a value" << endl;
        if(Tp != nullptr && is_owned)
        {
            delete Tp;
            Tp = nullptr;
        }
        this->C = C;
        return *this;
    }
    PyObject & operator=(int I)
    {
        cout << "PyObject got a value" << endl;
        if(Tp != nullptr && is_owned)
        {
            delete Tp;
            Tp = nullptr;
        }
        this->I = I;
        return *this;
    }
    PyObject & operator=(double D)
    {
        cout << "PyObject got a value" << endl;
        if(Tp != nullptr && is_owned)
        {
            delete Tp;
            Tp = nullptr;
        }
        // cout << "here" << endl;
        this->D = D;
        return *this;
    }
    PyObject & operator=(Test & T)
    {
        cout << "PyObject got a value\nBorrowing" << endl;
        // delete Tp;
        Tp = &T;
        return *this;
    }
    PyObject & operator=(Test && T)
    {
        cout << "PyObject got a value" << endl;
        Tp = new Test(move(T));
        cout << "Owning" << endl;
        is_owned = 1;
        return *this;
    }
    PyObject & operator=(PyObject & P)
    {
        cout << "PyObject got a value" << endl;
        C = P.C;
        I = P.I;
        D = P.D;
        Tp = P.Tp;
        if(P.is_owned) P.Tp = nullptr;
        return *this;
    }
    PyObject & operator=(PyObject * P)
    {
        cout << "PyObject got a value" << endl;
        C = P->C;
        I = P->I;
        D = P->D;
        Tp = P->Tp;
        cout << "Borrowing" << endl;
        return *this;
    }
    operator char() const { return C; }
    operator int() const { return I; }
    operator double() const { return D; }
    // operator Test() const { return *Tp; }
    operator Test&() const { return *Tp; }
    // ~PyObject() {delete Tp;}
};