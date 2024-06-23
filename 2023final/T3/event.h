#pragma once
#include <functional>
using namespace std;

class Click {
private:
public:
    std::function<void()> func;
    // TODO
    Click(function<void()> f = []{}) : func(f) {}
    // TODO
    void setClickCommand(std::function<void()> f) {func = f;}
    // TODO
    virtual void click() {func();}
};
class DoubleClick {
private:
public:
    std::function<void()> func;
    // TODO
    DoubleClick(function<void()> f = []{}) : func(f) {}
    // TODO
    void setDoubleClickCommand(std::function<void()> f) {func = f;}
    // TODO
    virtual void doubleClick() {func();}
};