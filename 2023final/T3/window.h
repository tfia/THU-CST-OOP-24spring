#pragma once
#include <memory>
#include <list>
#include <typeinfo>
#include <cmath>
#include "event.h"

using namespace std;

class Window;
class Checkbox;

class Widget {
    string _name;
    Window* _parent;
public:
    Widget(string name) :_name(name), _parent(nullptr) {}
    string getName() const { return _name; }
    Window* getParent() const { return _parent; }
    void setParent(Window * parent) {_parent = parent;}
    virtual ~Widget() {}
};

class Button :public Widget, public Click, public DoubleClick {
public:
    Button(string name) :Widget(name) {}
};


list<list<Checkbox*>> history;

class Checkbox :public Widget, public Click {
public:
    bool status;
    bool canUndo = false;
    void toggle()
    {
        status ^= 1;
    }
    Checkbox(string name) : Widget(name) {}
    virtual void click() override
    {
        list<Checkbox*> t;
        t.push_back(this);
        history.push_back(t);
        toggle();
    }
};

class Window {

private:

public:
    list<shared_ptr<Widget>> Widgets;
    // TODO
    shared_ptr<Widget> getPointerByName(string name)
    {
        for(auto it : Widgets)
        {
            if(it->getName() == name) return it;
        }
        return nullptr;
    }
    // TODO
    Widget& getElementByName(string name)
    {
        for(auto & it : Widgets)
        {
            if(it->getName() == name) return *it;
        }
    }
    // TODO
    bool addElement(shared_ptr<Widget> w)
    {
        if(getPointerByName(w->getName()) == nullptr)
        {
            Widgets.push_back(w);
            return true;
        }
        return false;
    }
    // TODO
    bool undo()
    {
        if(history.empty()) return false;
        auto t = history.back();
        history.pop_back();
        for(auto & it : t) it->toggle();
        return true;
    }
};
