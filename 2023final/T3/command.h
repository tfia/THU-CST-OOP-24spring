#pragma once
#include "window.h"
#include <iostream>
#include <memory>
#include <list>
using namespace std;

class ClearAll {
    list<shared_ptr<Checkbox>> checkbox;
public:
    // TODO
    ClearAll(list<shared_ptr<Checkbox>> checkbox) : checkbox(checkbox) {}
    void operator()()
    {
        list<Checkbox*> t;
        for(auto & it : checkbox)
        {
            if(it->status == 1) t.push_back(it.get());
            it->status = 0;
        }
        history.push_back(t);
    }
};

class SelectAll {
    list<shared_ptr<Checkbox>> checkbox;
public:
    // TODO
    SelectAll(list<shared_ptr<Checkbox>> checkbox) : checkbox(checkbox) {}
    void operator()()
    {
        list<Checkbox*> t;
        for(auto & it : checkbox)
        {
            if(it->status == 0) t.push_back(it.get());
            it->status = 1;
        }
        history.push_back(t);
    }
};

class Submit {
    list<shared_ptr<Checkbox>> checkbox;
public:
    // TODO
    Submit(list<shared_ptr<Checkbox>> checkbox) : checkbox(checkbox) {}
    void operator()()
    {
        for(auto & it : checkbox)
        {
            if(it->status == true) cout << it->getName() << " is selected" << endl;
            else  cout << it->getName() << " is not selected" << endl;
        }
    }
};